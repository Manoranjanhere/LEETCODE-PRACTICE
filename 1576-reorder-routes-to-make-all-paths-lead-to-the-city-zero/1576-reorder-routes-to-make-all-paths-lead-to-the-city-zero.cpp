class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int c=0;
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> vis(n,false);
        for(auto i:connections)
        {
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
        
            for(auto i:adj[curr])
            {
                if(!vis[i.first])
                {
                    q.push(i.first);
                    vis[i.first]=true;
                    c+=i.second;
                }
            }
        }
        return c;
    }
};