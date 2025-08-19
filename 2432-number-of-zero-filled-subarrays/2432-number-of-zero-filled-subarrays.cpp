class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0;
	long long ans = 0;
	long long count =0;
	int n = nums.size();
	for(int i=0;i<n;i++)
	{
		if(nums[i]==0)
		{
			ans+=1+count;
			count++;
		}
		else
		{
			c+=ans;
			ans=0;
			count=0;
		}
	}
	c+=ans;
	return c;
    }
};