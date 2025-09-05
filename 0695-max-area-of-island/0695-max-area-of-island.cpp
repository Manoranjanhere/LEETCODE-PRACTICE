class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
	int m = grid[0].size();
	int ans = 0;
	vector<vector<bool>>vis(n,vector<bool>(m,false));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]==1&& !vis[i][j])
			{
				int c=0;
				solve(grid,i,j,c,vis);
				ans=max(ans,c);
			}
		}
	}
	return ans;
    }
	void solve(vector<vector<int>>& grid,int i,int j,int& c,vector<vector<bool>>&vis)
	{
		if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]||grid[i][j]==0)
		{
			return;
		}
		vis[i][j]=true;
        c++;
		solve(grid,i+1,j,c,vis);
		solve(grid,i-1,j,c,vis);
		solve(grid,i,j+1,c,vis);
		solve(grid,i,j-1,c,vis);
	}

};