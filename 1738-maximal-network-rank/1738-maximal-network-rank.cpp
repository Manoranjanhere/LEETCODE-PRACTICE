class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>rank(n,0);
        vector<vector<bool>> conn(n,vector<bool>(n,false));
        for(auto i:roads)
        {
            rank[i[0]]++;
            rank[i[1]]++;
            conn[i[0]][i[1]]=true;
            conn[i[1]][i[0]]=true;
        }
        int ans =0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int k = rank[i]+rank[j]-(conn[i][j]?1:0);
                ans=max(ans,k);
            }
        }
        return ans;
    }
};