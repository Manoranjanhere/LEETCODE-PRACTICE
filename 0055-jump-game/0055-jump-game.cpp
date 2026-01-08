class Solution {
public:
    bool canJump(vector<int>& nums) {
		int n = nums.size();
		if(n<=1)return true;
		if(nums[0]==0)return false;
		int j=nums[0];
		for(int i=1;i<n;i++)
		{
			j=max(j-1,nums[i]);
			if(j==0&&i!=n-1)return false;
		}
		return true;
        }
};