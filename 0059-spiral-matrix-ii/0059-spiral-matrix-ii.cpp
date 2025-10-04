class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int  c=1;
        int left =0;
        int right =n-1;
        int down =n-1;
        int up=0;
        int k =1;
        while(k<=n*n)
        {
            for(int i=left;i<=right;i++)
            {
                ans[up][i]=k;
                k++;
            }
            up++;
            for(int i=up;i<=down;i++)
            {
                ans[i][right]=k;
                k++;
            }
            right--;
            for(int i=right;i>=left;i--)
            {
                ans[down][i]=k;
                k++;
            }
            down--;
            for(int j=down;j>=up;j--)
            {
                ans[j][left]=k;
                k++;
            }
            left++;
    }
    return ans;
    }
};