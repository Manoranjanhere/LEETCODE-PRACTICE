class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&vis,int m,int n)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int sz=q.size();
            for(int k=0;k<sz;k++)
            {
                pair<int,int> curr = q.front();
                q.pop();
                int x = curr.first;
                int y= curr.second;
                if(x+1<m&&grid[x+1][y]=='1'&&vis[x+1][y]==false)
                {
                    vis[x+1][y]=true;
                    q.push({x+1,y});
                }
                if(y+1<n&&grid[x][y+1]=='1'&&vis[x][y+1]==false)
                {
                    vis[x][y+1]=true;
                    q.push({x,y+1});
                }
                if(y>0&&grid[x][y-1]=='1'&&vis[x][y-1]==false)
                {
                    vis[x][y-1]=true;
                    q.push({x,y-1});
                }
                if(x>0&&grid[x-1][y]=='1'&&vis[x-1][y]==false)
                {
                    vis[x-1][y]=true;
                    q.push({x-1,y});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int c=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'&&vis[i][j]==false)
                {
                    c++;
                    bfs(grid,i,j,vis,m,n);
                }
            }
        }
        return c;
    }
};