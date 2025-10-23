class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2)
        {
            string k="";
            for(int i=1;i<s.size();i++)
            {
                k+=to_string(((s[i]-'0')+(s[i-1]-'0'))%10);
            }
            s=k;
        }
        if(s[0]==s[1])return true;
        return false;
    }
};