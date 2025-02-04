class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxx=nums[0];
        int sum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                sum+=nums[i];
            }
            else
            {
                sum=nums[i];
            }
            maxx=max(maxx,sum);
        }
        return maxx;
    }
};