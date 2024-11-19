class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;        // Tracks the current sum of the window
        long long maxSum = 0;     // Tracks the maximum sum of any valid window
        unordered_set<int> store; // Set to track unique elements in the current window
        int l = 0;                // Left pointer for the sliding window

        for (int r = 0; r < nums.size(); r++) {
            // If the current number is already in the set, shrink the window from the left
            while (store.find(nums[r]) != store.end()) {
                sum -= nums[l];        // Remove the leftmost element from the sum
                store.erase(nums[l]);  // Remove it from the set
                l++;                   // Move the left pointer forward
            }

            // Add the current number to the window
            sum += nums[r];
            store.insert(nums[r]);

            // If the window size equals k, update the maximum sum
            if (r - l + 1 == k) {
                maxSum = std::max(maxSum, sum);

                // Slide the window forward by removing the leftmost element
                sum -= nums[l];
                store.erase(nums[l]);
                l++;
            }
        }

        return maxSum;
    }
};
