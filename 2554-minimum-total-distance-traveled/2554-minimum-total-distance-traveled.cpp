#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long minimumTotalDistance(std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
        // Sort robots and factories to optimize pairing
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());
        
        // Create a memoization table for dynamic programming
        std::unordered_map<int, int> factoryCapacity;
        for (const auto& fac : factory) {
            factoryCapacity[fac[0]] = fac[1]; // factory[0]: position, factory[1]: capacity
        }

        // DP vector to store intermediate results
        std::vector<std::vector<long long>> memo(robot.size(), std::vector<long long>(factory.size(), -1));

        // Call the recursive function
        return solve(robot, factory, 0, 0, memo);
    }

private:
    // Recursive function with memoization to find the minimum distance
    long long solve(const std::vector<int>& robot, const std::vector<std::vector<int>>& factory, int robotIndex, int factoryIndex, std::vector<std::vector<long long>>& memo) {
        if (robotIndex >= robot.size()) {
            return 0; // All robots assigned, so no additional distance
        }
        if (factoryIndex >= factory.size()) {
            return LLONG_MAX; // No more factories left but still robots to assign
        }
        if (memo[robotIndex][factoryIndex] != -1) {
            return memo[robotIndex][factoryIndex];
        }

        long long minDist = solve(robot, factory, robotIndex, factoryIndex + 1, memo); // Skip this factory

        long long currentDist = 0;
        for (int i = 0; i < factory[factoryIndex][1] && robotIndex + i < robot.size(); ++i) {
            currentDist += abs(robot[robotIndex + i] - factory[factoryIndex][0]);
            long long nextDist = solve(robot, factory, robotIndex + i + 1, factoryIndex + 1, memo);
            if (nextDist != LLONG_MAX) {
                minDist = std::min(minDist, currentDist + nextDist);
            }
        }

        memo[robotIndex][factoryIndex] = minDist;
        return minDist;
    }
};
