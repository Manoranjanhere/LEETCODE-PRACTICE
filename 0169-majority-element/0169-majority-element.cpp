class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
	int maj = nums[0];
	int c=1;
	for(int i=1;i<n;i++)
	{
		if(c==0)
		{
			maj=nums[i];
			c=1;
		}
		else if(nums[i]!=maj)c--;
		else c++;
		
	}
	return maj;
    }
};