class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1)return n;
        int n1=1;
        int n2=2;
        for(int i=3;i<=n;i++)
        {
            int store =n1+n2;
            n1=n2;
            n2=store;
        }
        return n2;
    }
};