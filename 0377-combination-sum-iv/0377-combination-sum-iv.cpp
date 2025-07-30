class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
	int n = nums.size();
	vector<vector<int>>dp(n,vector<int>(target+1,-1));
	return solve(nums,target,dp,0);
    }
	int solve(vector<int>& nums, int target,vector<vector<int>>&dp,int ind)
	{
		if(target==0)
		{
			return 1;
		}
		if(ind==nums.size()||target<=0)
		{
			return 0;
		}
		if(dp[ind][target]!=-1)
		{
			return dp[ind][target];
		}
		int take=solve(nums,target-nums[ind],dp,0);
		int nottake=solve(nums,target,dp,ind+1);
		return dp[ind][target]=take+nottake;
	
	}
	
};