class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx=0;
	unordered_map<int,int> mp;
	for(int i:nums)
	{
		mp[i]++;
		mx=max(mx,mp[i]);
	}
	int ans =0;
	for(auto i:mp)
	{
		if(i.second==mx)
		{
			ans+=mx;
		}
	}
	return ans;
    }
};