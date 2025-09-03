class Solution {
public:
    vector<string> generateParenthesis(int n) {
	vector<string> ans;
        solve(0,0,"",ans,n);
	return ans;
    }
	void solve(int l,int r,string st,vector<string>&ans,int n)
	{
		if(l==r&&l+r==2*n)
		{
			ans.push_back(st);
			return;
		}
		if(l<n)
		{
			solve(l+1,r,st+"(",ans,n);
		}
		if(r<l)
		{
			solve(l,r+1,st+")",ans,n);
		}
	}
};