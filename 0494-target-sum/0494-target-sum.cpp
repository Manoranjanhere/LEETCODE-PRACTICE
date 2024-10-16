class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Memoization table: 2D array with size (nums.size() x 2001)
        // We use 2001 to handle sums from -1000 to +1000 (offset by 1000)
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return solve(nums, target, 0, 0, dp);
    }

    int solve(vector<int>& nums, int target, int sum, int index, vector<vector<int>>& dp) {
        // Base case: reached the end of the nums array
        if (index == nums.size()) {
            // If the sum equals the target, count this as a valid way
            return sum == target ? 1 : 0;
        }

        // If the result for this state is already computed, return it
        if (dp[index][sum + 1000] != -1) {
            return dp[index][sum + 1000];
        }

        // Recursively calculate the number of ways by adding or subtracting current number
        int add = solve(nums, target, sum + nums[index], index + 1, dp);
        int subtract = solve(nums, target, sum - nums[index], index + 1, dp);

        // Store the result in the dp table
        dp[index][sum + 1000] = add + subtract;

        // Return the total number of ways for this state
        return dp[index][sum + 1000];
    }
};
