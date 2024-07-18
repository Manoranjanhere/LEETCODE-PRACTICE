class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ls=0;
        int st=0;
        int maxx =0;
        unordered_map<char,bool> mp;
        for(char ch:s)
        {
            if(!mp[ch])
            {
                ls++;
                mp[ch]=true;
                maxx=max(maxx,ls);
            }
            else
            {
                while(mp[ch])
                {
                    mp[s[st]]=false;
                    st++;
                    ls--;
                }
                mp[ch]=true;
                ls++;
            }
        }
        return maxx;
    }
};