class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int l1=i+1;
            int r = n-1;
            while(l1<r)
            {
            if((nums[i]+nums[l1]+nums[r])>0)
            {
                r--;
            }
            else if((nums[i]+nums[l1]+nums[r])<0)
            {
                l1++;
            }
            else
            {
                
                ans.insert({nums[i],nums[l1],nums[r]});
                l1++;
                r--;
            }
        }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};