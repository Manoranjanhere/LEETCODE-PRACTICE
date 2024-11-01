class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int n = s.length();
        if(n<2)return s;
        ans=s[0];
        ans+=s[1];
        for(int i=2;i<n;i++)
        {
            if(s[i]==s[i-1]&&s[i]==s[i-2])
            {
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};