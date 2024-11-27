class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            adj[i].push_back(i+1);
        }
        
        auto sh = [&]()
        {
            queue<pair<int,int>>q;
            q.push({0,0});
            unordered_set<int>visit;
            visit.insert(0);
            while(!q.empty())
            {
                auto [cur,length]= q.front();
                q.pop();
                if(cur==n-1)return length;
                for(int nei : adj[cur])
                {
                    if(visit.find(nei)==visit.end())
                    {
                        q.push({nei,length+1});
                        visit.insert(nei);
                    }
                }
            }
            return -1;
        };
        vector<int> res;
        for(const auto& query: queries)
        {
            adj[query[0]].push_back(query[1]);
            res.push_back(sh());
        }
        return res;
    }
};