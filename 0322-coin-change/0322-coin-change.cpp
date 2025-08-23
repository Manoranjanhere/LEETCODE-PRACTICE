class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size()+1;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(coins,amount,dp,0);
        return(ans>=1e9)?-1:ans;
    }
    int solve(vector<int>& coins, int amount,vector<vector<int>>&dp,int ind)
    {
        if(amount==0)
        {
            return 0;
        }
        if(ind>=coins.size()||amount<0)
        {
            return 1e9;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nottake= solve(coins,amount,dp,ind+1);
        int take = 1+solve(coins,amount-coins[ind],dp,ind);

        return dp[ind][amount]=min(take,nottake);
    }
};