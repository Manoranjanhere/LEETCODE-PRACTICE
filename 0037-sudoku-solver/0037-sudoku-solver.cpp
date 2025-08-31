class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuboard(board);
    }
    bool solveSudokuboard(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k='1';k<='9';k++)
                    {
                        if(isvalid(board,i,j,k))
                        {
                            board[i][j]=k;
                            if(solveSudokuboard(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>&board,int i,int j,char k)
    {
        for(int n=0;n<9;n++)
        {
            if(board[i][n]==k)return false;
            if(board[n][j]==k)return false;
            if(board[3*(i/3)+n/3][3*(j/3)+n%3]==k)return false;
        }
        return true;
    }
};