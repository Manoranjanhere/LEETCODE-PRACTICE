class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
	sort(nums.begin(),nums.end());
	vector<vector<int>> ans;
	int n = nums.size();
	for(int i=0;i<n-2;i++)
	{
		if(i>0&&nums[i]==nums[i-1])continue;
		int k=i+1;
		int j = n-1;
		while(k<j)
		{
		int sum = nums[i]+nums[j]+nums[k];
		if(sum==0){ans.push_back({nums[i],nums[k],nums[j]});
		j--;
		k++;
		while(k<j&&nums[k]==nums[k-1])k++;
		while(j>k&&nums[j]==nums[j+1])j--;
		}
		else if(sum>0)j--;
		else k++;
		}
	}
    	return ans;
    }
};