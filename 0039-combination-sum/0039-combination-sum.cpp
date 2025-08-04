class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
	vector<int> store;
	solve(ans,candidates,target,0,store);
	return ans;
    }
	void solve(vector<vector<int>>& ans,vector<int>& candidates, int target, int ind,vector<int>& store)
	{
		if(target<=0||ind>=candidates.size()){
			if(target==0)ans.push_back(store);
			return;
		}
		solve(ans,candidates,target,ind+1,store);
		store.push_back(candidates[ind]);
		solve(ans,candidates,target-candidates[ind],ind,store);
		store.pop_back();
	}
};