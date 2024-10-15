class Solution {
public:
    long long minimumSteps(string s) {
        int ind =0;
        int z=0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                ind++;
            }
            else
            {
                break;
            }
        }
        long long sum=0;
        for(int i=ind+1;i<n;i++)
        {
            if(s[i]=='0')
            {
                sum+=i-ind;
                ind++;
            }
        }
        return sum;
    }
};