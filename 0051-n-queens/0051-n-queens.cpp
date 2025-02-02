class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(0,n,board,ans);
        return ans;
    }
    void solve(int ind,int row,vector<string> board,vector<vector<string>>&ans)
    {
        if(ind==row)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<row;i++)
        {
            if(isvalid(board,ind,i))
            {
                board[ind][i]='Q';
                solve(ind+1,row,board,ans);
                board[ind][i]='.';
            }
        }
    }
    bool isvalid(vector<string> board,int row,int col)
    {
        int drow=row;
        int dcol=col;
        while(col>=0&&row>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            row--;
            col--;
        }
        row=drow;
        col=dcol;
        while(row>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            row--;
        }
        row=drow;
        while(row>=0&&col<board.size())
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col++;
            row--;
        }
    return true;
    }
};