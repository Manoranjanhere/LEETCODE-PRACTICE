class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>  ans;
        vector<int> store;
        int l=0;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        solve(nums,ans,store,l,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>& store,int l,int n)
    {
        if(l==n)
        {
            if (find(ans.begin(), ans.end(), store) == ans.end())
            {
                ans.push_back(store);
            }
            return;
        }
        solve(nums,ans,store,l+1,n);
        store.push_back(nums[l]);
        solve(nums,ans,store,l+1,n);
        store.pop_back();
    }
};