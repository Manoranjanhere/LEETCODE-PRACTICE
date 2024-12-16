class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0;i<k;i++)
        {
            int min = INT_MAX;
            int index=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]<min)
                {
                    min=nums[j];
                    index=j;
                }
            }
            nums[index]*=multiplier;
        }
        return nums;
    }
};