class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m-1,n-1,dp,obstacleGrid);
    }
     int solve(int r,int d,int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid)
    {
        if(r>m||d>n)
        {
            return 0;
        }
        if(obstacleGrid[r][d]==1)
        {
            return 0;
        }
        if(r==m&&d==n)
        {
            return 1;
        }
        if(dp[r][d]!=-1)
        {
            return dp[r][d];
        }
        dp[r][d]=solve(r+1,d,m,n,dp,obstacleGrid)+solve(r,d+1,m,n,dp,obstacleGrid);
        return dp[r][d];
    }
};