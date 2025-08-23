class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans =0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,solve(matrix,i,j,i,j,dp));
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>& matrix,int previ,int prevj,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size()||(previ!=i||prevj!=j)&&(matrix[previ][prevj]>=matrix[i][j]))
        {
            return 0;
        }
        if(dp[i][j]!=0)return dp[i][j];
        int best = 1;
        best = max(best,1+solve(matrix,i,j,i-1,j,dp));
        best = max(best,1+solve(matrix,i,j,i,j-1,dp));
        best = max(best,1+solve(matrix,i,j,i+1,j,dp));
        best = max(best,1+solve(matrix,i,j,i,j+1,dp));
        return dp[i][j]=best;
    }
};