class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};