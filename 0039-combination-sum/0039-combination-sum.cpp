class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> st;
	solve(candidates,target,0,ans,st);
	return ans;
        }
	void solve(vector<int>& candidates, int target,int ind,vector<vector<int>>& ans,vector<int> st)
	{
		if(target==0)
		{
			ans.push_back(st);
			return;
        	}
		else if(target<0||ind>=candidates.size())
		{
			return;
		}
		solve(candidates, target,ind+1,ans,st);
		st.push_back(candidates[ind]);
		solve(candidates, target-candidates[ind],ind,ans,st);
		st.pop_back();
	}
};
