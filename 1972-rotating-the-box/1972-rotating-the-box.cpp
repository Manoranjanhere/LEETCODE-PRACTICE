class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& matrix) {
        int n = matrix.size();
        vector<vector<char>>ans(matrix[0].size(), vector<char>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='.'&& matrix[i][j-1]=='#')
                {
                    swap(matrix[i][j],matrix[i][j-1]);
                    if(j>=2)
                    {
                        j-=2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                ans[j][n-i-1]=matrix[i][j];
            }
        }
        
        return ans;
    }
};