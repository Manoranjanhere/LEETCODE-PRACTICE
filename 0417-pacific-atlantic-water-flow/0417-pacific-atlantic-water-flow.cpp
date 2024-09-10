class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        if(m<1)return {{}};

        vector<vector<int>> ans;

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            fill(heights, 0 , i, INT_MIN, pacific);
            fill(heights, m-1, i, INT_MIN, atlantic);
        }
        for(int i=0; i<m; i++){
            fill(heights, i, 0, INT_MIN, pacific);
            fill(heights, i, n-1, INT_MIN, atlantic);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    void fill(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& ocean){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size())return;

        if(ocean[i][j]==1)return;

        if(heights[i][j]<prev)return;

        ocean[i][j]=1;

        fill(heights, i+1, j, heights[i][j], ocean);
        fill(heights, i-1, j, heights[i][j], ocean);
        fill(heights, i, j+1, heights[i][j], ocean);
        fill(heights, i, j-1, heights[i][j], ocean);
    }
};