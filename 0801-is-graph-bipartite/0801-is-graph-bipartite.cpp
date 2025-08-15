class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            queue<int> q;
            if(!vis[i])
            {
                q.push(i);
                col[i]=1;
                vis[i]=true;
            }
            while(!q.empty())
            {
                int curr = q.front();
                q.pop();

                for(int neighbour:graph[curr])
                {
                    if(col[neighbour]==-1)
                    {
                        col[neighbour]=1-col[curr];
                        vis[neighbour]=true;
                        q.push(neighbour);
                    }
                    else if(col[neighbour]==col[curr])
                    {
                        return false;
                    }
                }
            }   
        }
        return true;
    }
};