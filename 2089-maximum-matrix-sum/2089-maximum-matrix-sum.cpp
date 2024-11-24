class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int c=0;
        int m=INT_MAX;
        int z=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    z++;
                }
                if(matrix[i][j]<0)
                {
                    sum+=matrix[i][j]*-1;
                    c++;
                    m=min(m,matrix[i][j]*-1); 
                }
                else
                {
                    sum+=matrix[i][j];
                    m=min(m,matrix[i][j]); 
                }
            }
        }
        cout<<m;
        if(c%2==0||z!=0)
        {
            return sum;
        }
        else
        {
            return sum-2*m;
        }
    }
};