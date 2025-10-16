class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==1&&(i==0||j==0||i==n-1||j==m-1))
                {
                    solve(i,j,grid,vis);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==1)
                {
                    c++;
                }
            }
        }
        return c;
    }
    void solve(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0||vis[i][j])
        {
            return;
        }
        vis[i][j]=true;
         solve(i+1,j,grid,vis);
         solve(i-1,j,grid,vis);
         solve(i,j-1,grid,vis);
         solve(i,j+1,grid,vis);
    }
};