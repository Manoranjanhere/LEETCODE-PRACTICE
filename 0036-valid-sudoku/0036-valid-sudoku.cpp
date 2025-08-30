class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!solve(board,i,j,board[i][j]-'0')) return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int i,int j,int k)
    {
        for(int m=0;m<board[0].size();m++)
        {
            if(m!=j&&board[i][m]=='0'+k)return false;
        }
        for(int n=0;n<board.size();n++)
        {
            if(n!=i&&board[n][j]=='0'+k)return false;
        }
        for(int n=i/3*3;n<i/3*3+3;n++)
        {
            for(int m=j/3*3;m<j/3*3+3;m++)
            {
                if((m!=j||n!=i)&&board[n][m]=='0'+k)return false;
            }
        }
        return true;
    }
};