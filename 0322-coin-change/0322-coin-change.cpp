class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
       int ans = solve(coins,amount,n,dp);
       return (ans==1e9)?-1:ans;
    }
    int solve(vector<int>& coins, int amount,int ind,vector<vector<int>>&dp)
    {
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=i/coins[0];
            }
        }
        for(int i=1;i<ind;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nottake = dp[i-1][j];
                int take = 1e9;
                if(j>=coins[i])
                {
                    take = 1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(take,nottake);
            }
        }
        return dp[ind-1][amount];
    }

};