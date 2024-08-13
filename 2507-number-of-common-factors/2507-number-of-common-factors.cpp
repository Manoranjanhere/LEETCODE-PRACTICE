class Solution {
public:
    int commonFactors(int a, int b) {
        int c = min(a,b);
        int co=0;
        for(int i=1;i<=c;i++)
        {
            if(a%i==0&&b%i==0)
            {
                co++;
            }
        }
        return co;
    }
};