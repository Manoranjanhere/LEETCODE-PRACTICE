class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n+2);
       dp[n]=0,dp[n+1]=0;
       for(int i=n-1;i>=0;i--)
       {
        int ans=0;
        ans=max(ans,dp[i+1]);
        ans=max(ans,dp[i+2]+nums[i]);
        dp[i]=ans;
       }
       return dp[0];
    }
};