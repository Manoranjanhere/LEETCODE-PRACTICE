class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        int ind =0;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> work;
        solve(candidates,target,ans,work,ind,n);
        return ans;
    }
    void solve(vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int> work,int ind,int n)
    {
        if(target==0)
        {
            ans.push_back(work);
            return;
        }
        if(ind==n||target<0)
        {
            return;
        }
        int next=ind;
        while(next+1<n&&candidates[next]==candidates[next+1])
        {
            next++;
        }
        solve(candidates,target,ans,work,next+1,n);
        work.push_back(candidates[ind]);
        solve(candidates,target-candidates[ind],ans,work,ind+1,n);
        work.pop_back();
    }
};