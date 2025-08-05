class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        int neg=1;
        long result=0;
        while(i<n&&s[i]==' ')
        {
            i++;
        }
        if(s[i]=='-'||s[i]=='+')
        {
            if(s[i]=='-')neg=-1;
            i++;
        }

        while(i<n)
        {
            if(!isdigit(s[i]))
            {
                return neg*result;
            }
            else
            {
                result=result*10+(s[i]-'0');
                if(result*neg>=INT_MAX)return INT_MAX;
                if(result*neg<=INT_MIN)return INT_MIN;
            }
            i++;
        }
        return neg*result;
    }
};