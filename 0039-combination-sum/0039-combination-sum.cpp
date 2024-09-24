class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) 
    {
        int n = cand.size();
        vector<vector<int>> ans;
        vector<int> store;
        solve(store,ans,cand,target,0,n);
        return ans;
    }
    void solve(vector<int>& store,vector<vector<int>>& ans,vector<int>& cand, int target,int l,int n)
    {
                if(target==0)
                {
                    ans.push_back(store);
                    return;
                }
           if(l==n||target<0)
           {
                return;
           }
           if(cand[l]<=target)
           {
                store.push_back(cand[l]);
                solve(store,ans,cand,target-cand[l],l,n);
                store.pop_back();
           }
           solve(store,ans,cand,target,l+1,n);
    }
};