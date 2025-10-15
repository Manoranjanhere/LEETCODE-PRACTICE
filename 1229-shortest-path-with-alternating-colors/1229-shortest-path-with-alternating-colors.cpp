class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // adjacency lists
        vector<vector<int>> adjRed(n), adjBlue(n);
        for(auto &e : redEdges) adjRed[e[0]].push_back(e[1]);
        for(auto &e : blueEdges) adjBlue[e[0]].push_back(e[1]);

        vector<int> dist(n, INT_MAX);
        vector<vector<bool>> vis(n, vector<bool>(2,false)); // [node][lastColor] 0=red, 1=blue

        queue<pair<int,int>> q; // (node, lastColor)
        
        // start from node 0 with both colors
        q.push({0,0}); // pretend last edge was red
        q.push({0,1}); // pretend last edge was blue
        vis[0][0] = vis[0][1] = true;

        int level = 0; // distance from node 0

        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                auto [node, color] = q.front();
                q.pop();
                dist[node] = min(dist[node], level);

                if(color == 0) { // last edge red → now can go blue
                    for(int nxt : adjBlue[node]) {
                        if(!vis[nxt][1]) {
                            vis[nxt][1] = true;
                            q.push({nxt, 1});
                        }
                    }
                } else { // last edge blue → now can go red
                    for(int nxt : adjRed[node]) {
                        if(!vis[nxt][0]) {
                            vis[nxt][0] = true;
                            q.push({nxt, 0});
                        }
                    }
                }
            }
            level++;
        }

        for(int i=0; i<n; i++) if(dist[i] == INT_MAX) dist[i] = -1;
        return dist;
    }
};
