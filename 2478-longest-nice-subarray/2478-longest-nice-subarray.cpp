class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLength = 1;  // Track the maximum nice subarray length found

        for (int start = 0; start < nums.size() - maxLength; start++) {
            int currentLength = 1;  // Length of current nice subarray
            int usedBits =
                nums[start];  // Track which bits are used in our subarray

            // Try to extend the subarray
            for (int end = start + 1; end < nums.size(); end++) {
                // If no bits overlap between current number and used bits, we
                // can extend
                if ((usedBits & nums[end]) == 0) {
                    usedBits |=
                        nums[end];  // Add new number's bits to our tracker
                    currentLength++;
                }
                // If bits overlap, this number can't be part of our nice
                // subarray
                else
                    break;
            }

            // Update max length if we found a longer nice subarray
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};