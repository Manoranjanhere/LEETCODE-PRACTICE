
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
	vector<vector<int>>dp(coins.size(),vector<int>(amount+1,1e9));
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 0;
        }
          for (int j = coins[0]; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            }
        }
       for(int i=1;i<coins.size();i++)
       {
        for(int j=1;j<=amount;j++)
        {
            if(j>=coins[i])
            {
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
       }
        int ans =dp[coins.size()-1][amount];
        if(ans==1e9)return -1;
        return ans;
	}
};
