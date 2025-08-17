class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevcol= image[sr][sc];
        if(prevcol==color)return image;
        solve(sr,sc,prevcol,color,image);
        return image;
    }
    void solve(int i,int j,int prevcol,int color,vector<vector<int>>&image)
    {
        if(i<0||i>=image.size()||j<0||j>=image[0].size())
        {
            return;
        }
        if(image[i][j]==prevcol)
        {
            image[i][j]=color;
            solve(i-1,j,prevcol,color,image);
            solve(i+1,j,prevcol,color,image);
            solve(i,j-1,prevcol,color,image);
            solve(i,j+1,prevcol,color,image);
        }
    }
};