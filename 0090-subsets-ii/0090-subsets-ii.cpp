class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int ind =0;
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> work;
        solve(nums,ans,work,ind,n);
        vector<vector<int>>anss(ans.begin(),ans.end());
        return anss;
    }
    void solve(vector<int> nums,set<vector<int>>& ans,vector<int> work,int ind,int n)
    {
        if(ind==n)
        {
            ans.insert(work);
            return;
        }
            solve(nums,ans,work,ind+1,n);
            work.push_back(nums[ind]);
            solve(nums,ans,work,ind+1,n);
    }

   
    
};
