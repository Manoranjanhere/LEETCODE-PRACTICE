class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                bool k=false;
                if(grid[i][j]==0&&!vis[i][j])
                {
                    if(solve(i,j,grid,vis))c++;
                }
            }
        }
        return c;
    }
    bool solve(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
        {
            return false;
        }
        if(grid[i][j]==1||vis[i][j])
        {
            return true;
        }
        vis[i][j]=true;
        bool up = solve(i+1,j,grid,vis);
        bool down = solve(i,j+1,grid,vis);
        bool left = solve(i-1,j,grid,vis);
        bool right = solve(i,j-1,grid,vis);
        return (up&&down&&left&&right);

    }
};