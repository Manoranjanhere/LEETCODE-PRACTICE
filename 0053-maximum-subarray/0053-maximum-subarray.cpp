class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[i]+sum)
            {
                sum=nums[i];
            }
            else
            {
                sum+=nums[i];
            }
            ans= max(ans,sum);
        }
        return ans;
    }
};