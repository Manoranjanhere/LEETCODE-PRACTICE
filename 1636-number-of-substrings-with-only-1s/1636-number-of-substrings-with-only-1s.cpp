class Solution {
public:
    int numSub(string s) {
        int c=0;
        long long ans =0;
        for(char ch:s)
        {
            if(ch=='1')
            {
                ans++;
                ans+=c;
                c++;
            }
            else
            {
                c=0;
            }
        }
        int k = ans%1000000007;
        return k;
    }
};