class Solution {
public:
    bool findPartitions(int startIndex, int sum, string stringNum, int target,
                        vector<vector<int>>& memo) {
        // Check if partition is valid
        if (startIndex == stringNum.size()) {
            return sum == target;
        }

        // Invalid partition found, so we return false
        if (sum > target) return false;

        // If the result for this state is already calculated, return it
        if (memo[startIndex][sum] != -1) return memo[startIndex][sum];

        bool partitionFound = false;

        // Iterate through all possible substrings starting with startIdx
        for (int currentIndex = startIndex; currentIndex < stringNum.size();
             currentIndex++) {
            // Create partition
            string currentString =
                stringNum.substr(startIndex, currentIndex - startIndex + 1);
            int addend = stoi(currentString);

            // Recursively check if valid partition can be found
            partitionFound =
                partitionFound || findPartitions(currentIndex + 1, sum + addend,
                                                 stringNum, target, memo);
            if (partitionFound == true) return true;
        }

        // Memoize the result for future reference and return its result
        return memo[startIndex][sum] = partitionFound;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;
        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            string stringNum = to_string(squareNum);

            // Initialize values in memoization array
            vector<vector<int>> memoArray(stringNum.size(),
                                          vector<int>(currentNum + 1, -1));

            // Check if valid partition can be found and add squared number if
            // so
            if (findPartitions(0, 0, stringNum, currentNum, memoArray)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};