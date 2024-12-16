class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        while(k--)
        {
            auto it = min_element(nums.begin(), nums.end());
            int index = distance(nums.begin(), it);
            nums[index]*=multiplier;
        }
        return nums;

    }
};