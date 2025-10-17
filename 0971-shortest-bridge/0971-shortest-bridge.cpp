class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        bool done =false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    solve(i,j,vis,grid);
                    done=true;
                    break;
                }
            }
            if(done)break;
        }
        int ans =1e9;
        queue<pair<int,int>> q;
        vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
        int level =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int sz= q.size();
            while(sz--)
            {
                auto [x,y]=q.front();
                q.pop();
                for(auto d:dir)
                {
                    int nx=x+d[0];
                    int ny=y+d[1];
                
                if(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size())continue;
                if(grid[nx][ny]==1)return level;
                if(grid[nx][ny]==0)
                {
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
                }
            }
            level++;
        }
        return -1;
    }
    void solve(int i,int j,vector<vector<bool>> &vis,vector<vector<int>>&grid)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||vis[i][j]||grid[i][j]==0)return;
        grid[i][j]=2;
        vis[i][j]=true;
        solve(i+1,j,vis,grid);
        solve(i,j+1,vis,grid);
        solve(i-1,j,vis,grid);
        solve(i,j-1,vis,grid);
    }
};