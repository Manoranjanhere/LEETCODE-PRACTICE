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
        if(start==nums.size())
        {
            result.push_back(path);
            return;
        }
        
            backtrack(nums,start+1,path,result);
            path.push_back(nums[start]);
            backtrack(nums,start+1,path,result);
            path.pop_back();
        
    }
    
};