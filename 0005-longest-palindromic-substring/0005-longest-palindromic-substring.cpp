class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int mxsize=0;
        string ele="";
        if(n==1)return s;
        if(n==0)return "";
        for(int i=0;i<n-1;i++)
        {
            for(int j=n-1;j>=i;j--)
            {
                if(s[i]==s[j])
                {
                    string ans =s.substr(i,j-i+1); 
                    if(ans.length()>mxsize&&pallindrome(ans))
                    {
                            ele=ans;
                            mxsize=ans.length();
                    }
                }
            }
        }
        return ele;
    }
    bool pallindrome(string a)
    {
        string rev=a;
        reverse(rev.begin(),rev.end());
        if(rev==a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};