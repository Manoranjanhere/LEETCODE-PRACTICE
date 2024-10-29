class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> memo(row,vector<int>(col,-1));
        int maxMoves = 0;
    for (int i = 0; i < row; i++) { 
        maxMoves = max(maxMoves, solve(grid, row, col, i, 0, memo));
    }
    return maxMoves;
    }
    int solve(vector<vector<int>>& grid,int & a,int &b,int row,int col,vector<vector<int>>&memo)
    {
        if(col==b-1)
        {
            return 0;
        }
         if (memo[row][col] != -1) 
         {
            return memo[row][col];
        }
        int sideu=0,sides=0,sided=0;
        if(row>0&&grid[row][col]<grid[row-1][col+1])
        {   
            sideu = 1+solve(grid,a,b,row-1,col+1,memo);
        }
        if(grid[row][col]<grid[row][col+1])
        {
             sides = 1+solve(grid,a,b,row,col+1,memo);
        }
        if(row+1<a&&grid[row][col]<grid[row+1][col+1])
        {
            sided = 1+solve(grid,a,b,row+1,col+1,memo);
        }
        return memo[row][col]=max({sideu,sides,sided});
    }
};