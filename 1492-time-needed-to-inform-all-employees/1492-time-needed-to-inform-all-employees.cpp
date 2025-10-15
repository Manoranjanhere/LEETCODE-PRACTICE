class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        int time=0;
        while(!q.empty())
        {
            auto [curr,t]=q.front();
            q.pop();
            time=max(time,t);
            for(int sub:adj[curr])
            {
                q.push({sub,t+informTime[curr]});
            }
        }
        return time;
    }
};