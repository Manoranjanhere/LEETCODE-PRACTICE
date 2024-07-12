class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m-1,n-1,dp);
    }
    int solve(int r,int d,int m,int n,vector<vector<int>>& dp)
    {
        if(r>m||d>n)
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
        dp[r][d]=solve(r+1,d,m,n,dp)+solve(r,d+1,m,n,dp);
        return dp[r][d];
    }
};