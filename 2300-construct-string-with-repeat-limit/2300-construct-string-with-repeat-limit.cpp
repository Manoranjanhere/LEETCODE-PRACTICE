class Solution {
public:
    string repeatLimitedString(string s, int r) {
        int n = s.length();
        string ans="";
        map<char,int, greater<int>>mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        while(!mp.empty())
        {
            auto i = mp.begin();
            char st=i->first;
            int fre=i->second; 
            int count = min(fre, r);
            ans.append(count, st);
            mp[st] -= count;
            if(mp[st]==0)
            {
                mp.erase(st);
            }
            else
            {
                if(mp.size()<=1)
                {
                    return ans;
                }
                else
                {
                    auto nextele=next(mp.begin());
                    ans+=nextele->first;
                    if(--nextele->second==0)
                    {
                        mp.erase(nextele);
                    }
                }
            }
        }
        return ans;
    }
};