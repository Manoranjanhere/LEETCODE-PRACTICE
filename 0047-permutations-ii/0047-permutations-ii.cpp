class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        solve(nums,ans,n,0);
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }
    void solve(vector<int>& nums,set<vector<int>>& ans,int n,int l)
    {
        if(l==n)
        {
            ans.insert(nums);
            return;
        }
        for(int i=l;i<nums.size();i++)
        {
            swap(nums[l],nums[i]);
            solve(nums,ans,n,l+1);
            swap(nums[l],nums[i]);
        }
    }
};