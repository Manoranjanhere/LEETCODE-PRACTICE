class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) 
    {
        int n = cand.size();
        sort(cand.begin(),cand.end());
        vector<vector<int>> ans;
        vector<int> store;
        solve(store,ans,cand,target,0,n);
        vector<vector<int>>an(ans.begin(),ans.end());
        return an;
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
                solve(store,ans,cand,target-cand[l],l+1,n);
                store.pop_back();
           }
            int nextIdx = l + 1;
        while (nextIdx < cand.size() && cand[nextIdx] == cand[l]) {
            nextIdx++;
        }
           solve(store,ans,cand,target,nextIdx,n);
    }
};