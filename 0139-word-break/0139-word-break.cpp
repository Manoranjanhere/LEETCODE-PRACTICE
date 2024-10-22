#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
            int len = s.length();
                    std::vector<bool> dp(len + 1, false);
                            dp[0] = true; // Base case: empty string can be formed

                                    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

                                            for (int i = 1; i <= len; i++) {
                                                        for (int j = 0; j < i; j++) {
                                                                        if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                                                                                            dp[i] = true;
                                                                                                                break; // Found a valid segmentation
                                                                                                                                }
                                                                                                                                            }
                                                                                                                                                    }

                                                                                                                                                            return dp[len]; // Return whether the entire string can be formed
                                                                                                                                                                }
                                                                                                                                                                };
                                                                                                                                                                