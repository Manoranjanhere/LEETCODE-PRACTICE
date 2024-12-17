class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        string ans="";
        sort(s.rbegin(),s.rend());
        int i=1;
        int c=1;
        ans+=s[0];
        int j=0;
        while(i<n)
        {
            if(s[i]==s[i-1])
            {
                c++;
            }
            else
            {
                c=1;
            }
            if(c>repeatLimit)
            {
                if(j<=i)
                {
                    j=i+1;
                }
                if(j==n)
                {
                    return ans;
                }
                while(s[j]==s[i])
                {
                    j++;
                    if(j==n)
                    {
                        return ans;
                    }
                }
                swap(s[i],s[j]);
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};