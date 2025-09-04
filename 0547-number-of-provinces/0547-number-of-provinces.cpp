class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    isConnected[j][i]=1;
                }
            }
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1&&!vis[i][j])
                {
                    c++;
                    solve(i,j,n,vis,isConnected);
                }
            }
        }
        return c;
    }
    void solve(int i,int j,int n,vector<vector<bool>>& vis,vector<vector<int>>& conn)
    {
        if(i<0||j<0||i>=n||j>=n||vis[i][j]||conn[i][j]!=1)
        {
            return;
        }
        vis[i][j]=true;
        solve(i+1,j,n,vis,conn);
        solve(i-1,j,n,vis,conn);
        solve(i,j+1,n,vis,conn);
        
    }
};