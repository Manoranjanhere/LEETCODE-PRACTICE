class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> st;
        solve(nums,ans,st,0);
        return ans;
    }
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&st,int ind)
    {
        if(ind==nums.size())
        {
            ans.push_back(st);
            return;
        }
        solve(nums,ans,st,ind+1);
        st.push_back(nums[ind]);
        solve(nums,ans,st,ind+1);
        st.pop_back();
    }
};