class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveS(board);
    }
    bool solveS(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k=1;k<=9;k++)
                    {
                        if(solve(i,j,board,k))
                        {
                            board[i][j]=k+'0';
                            if(solveS(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(int i,int j,vector<vector<char>>& board,int k)
    {
        for(int l=0;l<9;l++)
        {
            if(board[i][l]==k+'0')return false;
        }
        for(int l=0;l<9;l++)
        {
            if(board[l][j]==k+'0')return false;
        }
        int g1 = i/3*3;
        int g2= j/3*3;
        for(int l=g1;l<g1+3;l++)
        {
            for(int m=g2;m<g2+3;m++)
            {
                if(board[l][m]==k+'0')return false;
            }
        }
        return true;
    }
    
};