class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size();
	if(n<=1)return true;
	int k = nums[0];
    if(k==0)return false;
	k--;
	for(int i=1;i<n;i++)
	{
        k=max(k,nums[i]);
		if(k<=0&&i!=n-1)
		{
			return false;
		}
		k--;
	}
        return true;
    }
};