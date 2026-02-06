class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0]&&board[i][0]=='O')
            {
                solve1(i,0,vis,board);
            }
            if(!vis[i][m-1]&&board[i][m-1]=='O')
            {
                solve1(i,m-1,vis,board);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i]&&board[0][i]=='O')
            {
                solve1(0,i,vis,board);
            }
            if(!vis[n-1][i]&&board[n-1][i]=='O')
            {
                solve1(n-1,i,vis,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
	void solve1(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& board)
	{
		if(i<0||j<0||i>=board.size()||j>=board[0].size()||vis[i][j]||board[i][j]=='X')
		{
			return;
		}
		vis[i][j]=1;
		solve1(i-1,j,vis,board);
		solve1(i+1,j,vis,board);
		solve1(i,j+1,vis,board);
		solve1(i,j-1,vis,board);
	}
};