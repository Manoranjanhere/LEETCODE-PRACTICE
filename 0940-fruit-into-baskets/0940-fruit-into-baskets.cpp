class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int start=0;
        int m=0;
        int n = fruits.size();
       for(int i=0;i<n;i++)
       {
            mp[fruits[i]]++;
            while(mp.size()>2)
            {
                mp[fruits[start]]--;
                if(mp[fruits[start]]==0)
                {
                    mp.erase(fruits[start]);
                }
                start++;
            }
            m=max(m,(i-start+1));
       }
       return m;
    }
};
