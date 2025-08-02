class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            solve(heights,pacific,i,0,INT_MIN);
            solve(heights,atlantic,i,m-1,INT_MIN);
        }
        for(int j=0;j<m;j++)
        {
            solve(heights,pacific,0,j,INT_MIN);
            solve(heights,atlantic,n-1,j,INT_MIN);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]==1&&atlantic[i][j]==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void solve(vector<vector<int>>& heights,vector<vector<int>>& ocean,int i, int j,int prev)
    {
        if(i<0||i>=heights.size()||j<0||j>=heights[0].size()||ocean[i][j]==1||heights[i][j]<prev)return;
        ocean[i][j]=1;
        solve(heights,ocean,i-1,j,heights[i][j]);
        solve(heights,ocean,i,j+1,heights[i][j]);
        solve(heights,ocean,i+1,j,heights[i][j]);
        solve(heights,ocean,i,j-1,heights[i][j]);
    }

};