class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ind = coins.size();
        vector<vector<int>>dp(ind,vector<int>(amount+1,-1));
        int ans =solve(coins,ind-1,amount,dp);
        if(ans==1e9)
        {
            return -1;
        }
        return ans;
    }
    int solve(vector<int>& coins,int ind, int amount,vector<vector<int>>&dp)
    {
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        if(ind==0)
        {
            if(amount%coins[ind]==0)
            {
                return amount/coins[ind];
            }
            return 1e9;
        }

        int nottake=0+solve(coins,ind-1,amount,dp);
        int take=1e9;
        if(amount-coins[ind]>=0)
        {
            take=1+solve(coins,ind,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(nottake,take);
    }
};