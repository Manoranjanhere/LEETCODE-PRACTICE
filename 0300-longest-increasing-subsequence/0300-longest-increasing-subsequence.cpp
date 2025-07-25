class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n,1);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(nums[i]<nums[j])
			{
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
	}
	return *max_element(dp.begin(),dp.end());
     }
};