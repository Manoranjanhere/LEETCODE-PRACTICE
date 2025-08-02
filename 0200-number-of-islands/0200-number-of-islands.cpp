class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j])
                {
                    ans++;
                    solve(grid,vis,i,j);
                }

            }
        }
        return ans;
    }
    void solve(vector<vector<char>>& grid,vector<vector<int>>&vis,int i,int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0'||vis[i][j]==1)return;
        vis[i][j]=1;
        solve(grid,vis,i+1,j);
        solve(grid,vis,i,j+1);
        solve(grid,vis,i-1,j);
        solve(grid,vis,i,j-1);
    }
};