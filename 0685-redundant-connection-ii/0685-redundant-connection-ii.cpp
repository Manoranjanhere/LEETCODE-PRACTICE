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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        vector<int> indegree(n+1,-1);
        int e1=-1;int e2=-1;
        for(int i=0;i<n;i++)
        {
            int v = edges[i][1];
            if(indegree[v]==-1)
            {
                indegree[v]=i;
            }
            else
            {
                e1=indegree[v];
                e2=i;
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(i == e2) continue;
            int a= edges[i][0];
            int b= edges[i][1];
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)
            {
                if(e1==-1)return edges[i];
                else return edges[e1];
            }
            else
            {
                parent[pb]=pa;
            }
        }
        return edges[e2];
    }
};