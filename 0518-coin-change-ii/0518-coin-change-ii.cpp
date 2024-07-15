class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,0,n,amount,dp);
    }
    int solve(vector<int>& coins,int i,int n,int amount,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }
        if(i==n||amount<0)
        {
            return 0;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        dp[i][amount]=solve(coins,i,n,amount-coins[i],dp)+solve(coins,i+1,n,amount,dp);
        return dp[i][amount];
    }
};