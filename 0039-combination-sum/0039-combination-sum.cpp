class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> work;
        int ind =0;
        int n = candidates.size();
        solve(candidates,target,ans,work,ind,n);
        return ans;
    }
    void solve(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int> work,int ind,int n)
    {
        
            if(target==0)
            {
                ans.push_back(work);
                return;
            }
            if(ind>=n||target<0)
            {
                return;
            }
        
       
            work.push_back(candidates[ind]);
            solve(candidates,target-candidates[ind],ans,work,ind,n);
            work.pop_back();
        
        solve(candidates,target,ans,work,ind+1,n);
    }
};