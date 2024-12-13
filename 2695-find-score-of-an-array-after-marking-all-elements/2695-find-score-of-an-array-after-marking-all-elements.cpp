class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long sum=0;
        int n = nums.size();
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++)
        {
            mp.push_back({nums[i],i});
        }
        sort(mp.begin(),mp.end());
        int c=0;
        unordered_map<int,bool>num;
        for(int i=0;i<n;i++)
        {
            num.insert({i,false});
        }
        while(c<n)
        {
            auto fir =mp[c];
            c++;
            if(!num[fir.second])
            {
                sum+=fir.first;
                int sec = fir.second;
                num[sec]=true;
                if(sec!=0&&num[sec-1]!=true)
                {
                    num[sec-1]=true;
                }
                if(sec!=n-1&&num[sec+1]!=true)
                {
                    num[sec+1]=true;
                }
            }
        }
        return sum;
    }
};