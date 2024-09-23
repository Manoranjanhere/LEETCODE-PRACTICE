class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> run;
        solve(ans,run,n,k,1);
        return ans;
    }
    void solve(vector<vector<int>>& ans,vector<int>& run,int n,int k,int s)
    {
        if(run.size()==k)
        {
            ans.push_back(run);
            return;
        }
        for(int i=s;i<=n;i++)
        {
            run.push_back(i);
            solve(ans,run,n,k,i+1);
            run.pop_back();
        }
    }
};