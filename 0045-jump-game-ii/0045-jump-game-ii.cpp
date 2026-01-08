class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return 0;
	vector<int> st(n);
	st[0]=nums[0];
	for(int i=1;i<n;i++)
	{
		st[i]=max(st[i-1]-1,nums[i]);
	}
	int step=1;
	int k=nums[0];
	while(k<n-1)
	{
		k+=st[k];
		step++;
	}
	return step;
    }
};