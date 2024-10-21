#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            // Initialize the DP array with amount + 1 (which is an impossible value)
                    vector<int> dp(amount + 1, amount + 1);
                            dp[0] = 0; // Base case: 0 coins needed to make amount 0

                                    // Fill the DP table
                                            for (int i = 1; i <= amount; i++) {
                                                        for (const int& coin : coins) {
                                                                        if (i - coin >= 0) { // Ensure we don't go negative
                                                                                            dp[i] = min(dp[i], dp[i - coin] + 1); // Update dp[i]
                                                                                                            }
                                                                                                                        }
                                                                                                                                }

                                                                                                                                        // Return the result
                                                                                                                                                return (dp[amount] == amount + 1) ? -1 : dp[amount];
                                                                                                                                                    }
                                                                                                                                                    };
                                                                                                                                                    