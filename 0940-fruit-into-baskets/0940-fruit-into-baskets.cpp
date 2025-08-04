class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int c=0;
        int ind = 0;
        int ans=INT_MIN;
        for(int i:fruits)
        {
            mp[i]++;
            c++;
            while(mp.size()>2)
            {
                mp[fruits[ind]]--;
                if(mp[fruits[ind]]==0)mp.erase(fruits[ind]);
                ind++;
                c--;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};