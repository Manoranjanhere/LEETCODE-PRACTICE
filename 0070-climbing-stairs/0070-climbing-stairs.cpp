class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n);
        if(n==0||n==1)return n;
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};