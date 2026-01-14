class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool valid=true;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                        if(!solve(i,j,board,board[i][j]))
                        {
                            valid=false;
                            break;
                        }
                }
            }
            if(!valid)return false;
        }
        return true;
    }
    bool solve(int i,int j,vector<vector<char>>& board,int k)
    {
        for(int l=0;l<9;l++)
        {
            if(board[i][l]==k&&l!=j)return false;
        }
        for(int l=0;l<9;l++)
        {
            if(board[l][j]==k&&l!=i)return false;
        }
        int g1 = i/3*3;
        int g2= j/3*3;
        for(int l=g1;l<g1+3;l++)
        {
            for(int m=g2;m<g2+3;m++)
            {
                if(board[l][m]==k&&(l!=i||m!=j))
                {return false;}
            }
        }
        return true;
    }
};