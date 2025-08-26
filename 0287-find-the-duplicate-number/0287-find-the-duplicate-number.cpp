class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i:nums)
        {
            i=abs(i);
            if(nums[i-1]<0)
            {
                return i;
            }
            else
            {
                nums[i-1]=-nums[i-1];
            }
        }
        return 0;
    }
};