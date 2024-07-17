class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        // Use a 2D vector with only 2 rows to save space
        vector<vector<int>> dp(2, vector<int>(n2 + 1, 0));

        // Fill the dp array
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                } else {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }

        // The result is in dp[n1 % 2][n2]
        return dp[n1 % 2][n2];
    }
};
