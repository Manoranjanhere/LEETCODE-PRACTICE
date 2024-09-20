class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(nums,0,path,ans);
        return ans;
    }
    void backtrack(vector<int>& nums,int start, vector<int>&path,vector<vector<int>>& result)
    {
        result.push_back(path);
        for(int i=start;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            backtrack(nums,i+1,path,result);
            path.pop_back();
        }
        
    }
    
};