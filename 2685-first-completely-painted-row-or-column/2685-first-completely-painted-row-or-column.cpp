class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n);
        vector<int>col(m);
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            auto [r,c]=mp[arr[i]];
            row[r]++;
            col[c]++;
            if(row[r]==m||col[c]==n)return i;
        }
        return -1;
    }
};