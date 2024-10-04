class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int sum=0;
        long long ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            sum+=skill[i];
            mp[skill[i]]++;
        }
        if(sum%(n/2)!=0)
        {
            return -1;
        }
        int each = sum/(n/2);
        for(auto &i:mp)
        {
            int first = i.first;
            while(i.second)
            {
                mp[first]--;
                int extra = each-i.first;
                if(mp.find(extra)!=mp.end()&&mp[extra]>0)
                {
                    ans+=i.first*extra;
                    mp[extra]--;
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};