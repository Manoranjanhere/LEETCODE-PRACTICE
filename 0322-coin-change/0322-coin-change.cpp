class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int n=solve(0,coins,amount,dp);
        return n==INT_MAX?-1:n;
    }
    int solve(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(i>=coins.size()||amount<=0){
       if(amount==0) return 0;
       return INT_MAX;}
        if(dp[i][amount]!=-1)return dp[i][amount];

        int include=solve(i,coins,amount-coins[i],dp);
        if(include!=INT_MAX)include++;
        int exclude=solve(i+1,coins,amount,dp);
        
        return dp[i][amount]= min(include,exclude);
    }
};