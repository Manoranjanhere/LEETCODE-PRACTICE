class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int c=0;
        for(string i:words)
        {
            if(i.length()>=n&&i.substr(0,n)==pref)
            {
                c++;
            }
        }
        return c;
    }
};