class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp(n,1);
        int maxx=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]<nums[j])
                {
                    dp[j]=max(dp[j],1+dp[i]);
                }
            }
        }
        maxx = *max_element(dp.begin(),dp.end());
        return maxx;
    }
};