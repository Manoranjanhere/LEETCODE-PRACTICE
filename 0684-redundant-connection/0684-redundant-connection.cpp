class Solution {
public:
        vector<int> rank;
        vector<int> parent;
    int find(int a)
    {
        if(parent[a]!=a)
        {
            parent[a]=find(parent[a]);
        }
        return parent[a];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            int a= edges[i][0];
            int b= edges[i][1];
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)return{a,b};
            else
            {
                if(rank[pa]>rank[pb])
                {
                    parent[pb]=pa;
                }
                else if(rank[pa]<rank[pb])
                {
                   parent[pa]=pb;
                }
                else
                {
                    rank[pb]++;
                    parent[pa]=pb;
                }
            }
        }
        return {};
    }
};