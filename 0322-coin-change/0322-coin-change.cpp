class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int st = solve(0,coins,amount,dp);
        return (st>=INT_MAX-1)?-1:st;
    }
    int solve(int ind,vector<int>& coins, int amount,vector<vector<int>>& dp)
    {
        if(amount==0) return 0;
        else if(amount<0||ind>=coins.size())return INT_MAX-1;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
	int nottake=solve(ind+1,coins,amount,dp);
	int take=1+solve(ind,coins,amount-coins[ind],dp);
	return dp[ind][amount]=min(nottake,take);
    }
};