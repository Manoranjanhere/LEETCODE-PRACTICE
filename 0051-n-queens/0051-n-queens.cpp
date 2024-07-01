class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(board,0,n,ans);
        return ans;
    }
    void solve(vector<string>& board,int row,int n,vector<vector<string>>& ans)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(issafe(i,board,row,n))
            {
                board[row][i]='Q';
                solve(board,row+1,n,ans);
                board[row][i]='.';
            }

        }
    }
    bool issafe(int col,vector<string>& board,int row,int n)
    {
        int drow=row;
        int dcol=col;
        while(row>=0&&col>=0)
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
         col=dcol;
        while(col<n&&row>=0)
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