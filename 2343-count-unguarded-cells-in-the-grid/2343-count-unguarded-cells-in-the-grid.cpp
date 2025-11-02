class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(auto i:walls)
        {
            dp[i[0]][i[1]]=2;
        }
        for(auto i:guards)
        {
            dp[i[0]][i[1]]=3;
        }
        for(auto i:guards)
        {
            solve(i[0],i[1],guards,dp);
        }
        int ans =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
    void solve(int i,int j,vector<vector<int>>& g,vector<vector<int>>& dp)
    {
        int n = dp.size();
        int m = dp[0].size();
        for(int y=i+1;y<n&&dp[y][j]!=2&&dp[y][j]!=3;y++)
        {
            dp[y][j]=1;
        }
        for(int y=i-1;y>=0&&dp[y][j]!=2&&dp[y][j]!=3;y--)
        {
            dp[y][j]=1;
        }
        for(int y=j+1;y<m&&dp[i][y]!=2&&dp[i][y]!=3;y++)
        {
            dp[i][y]=1;
        }
        for(int y=j-1;y>=0&&dp[i][y]!=2&&dp[i][y]!=3;y--)
        {
            dp[i][y]=1;
        }
    }
};