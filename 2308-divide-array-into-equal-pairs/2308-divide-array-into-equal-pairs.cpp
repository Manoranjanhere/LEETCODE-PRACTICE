class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Track unpaired numbers
        unordered_set<int> unpaired;

        // Add numbers to set if unseen, remove if seen
        for (int num : nums) {
            if (unpaired.count(num)) {
                unpaired.erase(num);
            } else {
                unpaired.insert(num);
            }
        }

        // Return true if all numbers were paired
        return unpaired.empty();
    }
};