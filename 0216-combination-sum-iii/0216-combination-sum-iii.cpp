class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> store;
        solve(ans,store,k,n,0,1);
        return ans;
    }
    void solve(vector<vector<int>>& ans,vector<int>& store,int k,int target,int l,int i)
    {
        if(l==k)
        {
            if(target==0)
            {
                ans.push_back(store);
            }
            return;
        }
        else if(target<0||i>9)
        {
            return;
        }
        
            store.push_back(i);
            solve(ans,store,k,target-i,l+1,i+1);
            store.pop_back();
            solve(ans,store,k,target,l,i+1);
        
    }
};