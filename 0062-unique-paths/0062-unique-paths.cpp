class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D vector dp with m rows and n columns initialized to 1
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Iterate over the grid starting from cell (1,1)
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // The number of ways to reach cell (i,j) is the sum of ways to reach (i-1,j) and (i,j-1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // The bottom-right cell contains the number of unique paths
        return dp[m-1][n-1];
    }
};
