class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans = solve(coins,amount,n-1,dp);
       return (ans==1e9)?-1:ans;
    }
    int solve(vector<int>& coins, int amount,int ind,vector<vector<int>>&dp)
    {
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        if(ind==0)
        {
            if(amount%coins[ind]==0)
            {
                return amount/coins[ind];
            }
            else
            {
                return 1e9;
            }
        }
        int nottake= solve(coins,amount,ind-1,dp);
        int take = 1e9;
        if(amount>=coins[ind])
        {
            take =1+solve(coins,amount-coins[ind],ind,dp);
        }
        return dp[ind][amount] = min(take,nottake);
    }

};