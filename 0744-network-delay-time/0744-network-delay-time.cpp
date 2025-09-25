class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto [t,src]=pq.top();
            pq.pop();
            if(t>dist[src])continue;
            for(auto [nei,wt]:adj[src])
            {
                if(wt+dist[src]<dist[nei])
                {
                    dist[nei]=dist[src]+wt;
                    pq.push({dist[nei],nei});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(dist[i],ans);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};