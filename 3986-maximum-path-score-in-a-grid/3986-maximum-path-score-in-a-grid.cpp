class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        // dp[i][j][k] = max score from (i,j) to end using k power-ups left
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, INT_MIN)));
        
        int ans = solve(0, 0, k, grid, dp);
        return ans < 0 ? -1 : ans;
    }

    int solve(int i, int j, int k, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        // out of bounds
        if(i >= n || j >= m) return -1e9;

        // if cell requires power but no power left
        if(grid[i][j] != 0 && k == 0) return -1e9;

        // end cell
        if(i == n-1 && j == m-1) return grid[i][j];

        // memo
        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int nk = k;
        if(grid[i][j] != 0) nk--;

        int right = solve(i, j+1, nk, grid, dp);
        int down = solve(i+1, j, nk, grid, dp);

        int best = grid[i][j] + max(right, down);
        return dp[i][j][k] = best;
    }
};
