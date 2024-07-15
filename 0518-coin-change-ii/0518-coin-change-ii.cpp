class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        return solve(coins,0,n,amount,dp);
    }
    int solve(vector<int>& a,int i,int n,int amount,vector<vector<int>>&dp)
    {
        dp[n][amount]=1;
       for(int i=n-1;i>=0;i--)
       {
        for(int j=amount;j>=0;j--)
        {
            dp[i][j]=dp[i+1][j];
            if(j+a[i]<=amount)
            {
                dp[i][j]+=dp[i][j+a[i]];
            }
        }
       }
       return dp[0][0];
    }
};