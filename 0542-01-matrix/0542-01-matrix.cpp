class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();
            for(auto d:dir)
            {
                int ni=i+d[0];
                int nj=j+d[1];
                if(ni<0||nj<0||ni>=n||nj>=m)continue;
                if(dist[ni][nj]!=-1)continue;
                dist[ni][nj]=dist[i][j]+1;
                q.push({ni,nj});
            }
        }
        return dist;
    }
};