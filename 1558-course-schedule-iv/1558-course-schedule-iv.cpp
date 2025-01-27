class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int i=0;i<prerequisites.size();i++)
        {
            int j = prerequisites[i][0];
            int k = prerequisites[i][1];
            mat[j][k]=1;
        }
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                    for(int k=0;k<mat.size();k++)
                    {
                        if(mat[j][i]==1&&mat[i][k]==1)
                        {
                            mat[j][k]=1;
                        }
                    }
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++)
        {
            int j = queries[i][0];
            int k = queries[i][1];
            if(mat[j][k]==1)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};