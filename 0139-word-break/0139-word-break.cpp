#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_map<std::string, bool> dp;
        return solve(s, wordDict, dp);
    }

private:
    bool solve(std::string s, std::vector<std::string>& wordDict, std::unordered_map<std::string, bool>& dp) {
        if (s.empty()) {
            return true; // Base case: If s is empty, we've successfully segmented it
        }

        if (dp.find(s) != dp.end()) {
            return dp[s]; // Return memoized result if we already computed this substring
        }

        for (const std::string& word : wordDict) {
            if (s.substr(0, word.size()) == word) { // Check if s starts with the word
                std::string remainder = s.substr(word.size()); // Remaining substring after removing the word
                if (solve(remainder, wordDict, dp)) {
                    dp[s] = true; // Memoize and return true if we found a valid segmentation
                    return true;
                }
            }
        }

        dp[s] = false; // Memoize and return false if no segmentation found
        return false;
    }
};
