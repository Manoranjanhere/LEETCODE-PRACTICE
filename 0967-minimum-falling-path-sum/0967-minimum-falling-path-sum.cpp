class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Create a memoization table with dimensions m x n
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        // Initialize minSum to a large value
        int minSum = INT_MAX;
        
        // Iterate through each column in the first row
        for (int j = 0; j < n; ++j) {
            // Find the minimum path sum starting from each column in the first row
            minSum = min(minSum, solve(0, j, matrix, dp));
        }
        
        return minSum;
    }

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Base case: when we reach the last row
        if (i == m - 1) {
            return matrix[i][j];
        }
        
        // Check if the result for (i, j) has already been computed
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        
        // Recursive calls for the next row
        int left = (j > 0) ? solve(i + 1, j - 1, matrix, dp) : INT_MAX;
        int down = solve(i + 1, j, matrix, dp);
        int right = (j < n - 1) ? solve(i + 1, j + 1, matrix, dp) : INT_MAX;
        
        // Compute the minimum path sum including the current cell
        dp[i][j] = matrix[i][j] + min({left, down, right});
        
        return dp[i][j];
    }
};
