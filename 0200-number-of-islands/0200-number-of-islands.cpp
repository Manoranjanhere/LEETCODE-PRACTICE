class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        if(grid.empty())return ans;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
	    {
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j]&&grid[i][j]=='1')
			{
				ans++;
				solve(vis,grid,i,j);
			}
		}
	    }
        return ans;
    }
    void solve(vector<vector<int>>&vis,vector<vector<char>>&grid,int i,int j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0'||vis[i][j])return;
        vis[i][j]=1;
        solve(vis,grid,i-1,j);
        solve(vis,grid,i+1,j);
        solve(vis,grid,i,j-1);
        solve(vis,grid,i,j+1);
        
    }
};