class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
	unordered_map<int,int> st;
	for(int i:nums)
	{
		if(st[i]<2)
		{
			nums[k]=i;
			st[i]++;
			k++;
		}
	}
	return k;
    }
};