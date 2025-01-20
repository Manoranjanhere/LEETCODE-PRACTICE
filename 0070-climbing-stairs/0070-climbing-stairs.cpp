class Solution {
public:
    int climbStairs(int n) 
    {
        return solve(n);
       
    }
    int solve(int n)
    {
        if(n<=2)
        {
            return n;
        }
        int prev1=2;
        int prev2=1;
        int curr=0;
        for(int i=3;i<=n;i++)
        {

            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};