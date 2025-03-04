class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> mp;
        if(s.length()<k)return false;
        if(s.length()==k)return true;
        for(char ch:s)
        {
            mp[ch]++;
        }
        int c=0;
        for(auto i:mp)
        {
            if(i.second%2!=0)
            {
                c++;
            }
        }
        return(c<=k);
    }
};