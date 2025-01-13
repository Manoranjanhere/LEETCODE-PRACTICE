class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        int n = s.length();
        if(n%2!=0)return false;
        int open=0;
        int flex=0;
        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            {
                flex++;
            }
            else if(s[i]=='(')
            {
                open++;
            }
            else
            {
                if(open>0)
                {
                    open--;
                }
                else if(flex>0)
                {
                    flex--;
                }
                else
                {
                    return false;
                }
            }
        }
        int close=0;
        flex=0;
        for(int i=n-1;i>=0;i--)
        {
            if(locked[i]=='0')
            {
                flex++;
            }
            else if(s[i]==')')
            {
                close++;
            }
            else
            {
                if(close>0)
                {
                    close--;
                }
                else if(flex>0)
                {
                    flex--;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};