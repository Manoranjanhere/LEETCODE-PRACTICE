class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return solve(nums, target, 0, 0, dp);
    }

    int solve(vector<int>& nums, int target, int sum, int index, vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        if (dp[index][sum + 1000] != -1) {
            return dp[index][sum + 1000];
        }
        int add = solve(nums, target, sum + nums[index], index + 1, dp);
        int subtract = solve(nums, target, sum - nums[index], index + 1, dp);

        dp[index][sum + 1000] = add + subtract;

        return dp[index][sum + 1000];
    }
};
