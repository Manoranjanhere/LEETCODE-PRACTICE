class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n =matrix.size();
        int c=0;
        int st=0;
        vector<int> ans;
        // for(int i=0;i<n;i++)
        // {
        //     if(c+matrix[i].size()<k)
        //     {
        //         c+=matrix[i].size();
        //     }
        //     else
        //     {
        //         st=i;
        //         cout<<st;
        //         break;
        //     }
        // }
        // return matrix[st][k-c-1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];

    }
};