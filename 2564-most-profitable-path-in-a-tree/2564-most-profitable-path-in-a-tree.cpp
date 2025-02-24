class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size(), maxIncome = INT_MIN;
        tree.resize(n);
        visited.assign(n, false);
        queue<vector<int>> nodeQueue;
        nodeQueue.push({0, 0, 0});

        // Form tree with edges
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Find the path taken by bob to reach node 0 and the times it takes to
        // get there
        findBobPath(bob, 0);

        // Breadth First Search
        visited.assign(n, false);
        while (!nodeQueue.empty()) {
            int sourceNode = nodeQueue.front()[0], time = nodeQueue.front()[1],
                income = nodeQueue.front()[2];

            // Alice reaches the node first
            if (bobPath.find(sourceNode) == bobPath.end() ||
                time < bobPath[sourceNode]) {
                income += amount[sourceNode];
            }

            // Alice and Bob reach the node at the same time
            else if (time == bobPath[sourceNode]) {
                income += (amount[sourceNode] / 2);
            }

            // Update max value if current node is a new leaf
            if (tree[sourceNode].size() == 1 && sourceNode != 0) {
                maxIncome = max(maxIncome, income);
            }
            // Explore adjacent unvisited vertices
            for (int adjacentNode : tree[sourceNode]) {
                if (!visited[adjacentNode]) {
                    nodeQueue.push({adjacentNode, time + 1, income});
                }
            }

            // Mark and remove current node
            visited[sourceNode] = true;
            nodeQueue.pop();
        }
        return maxIncome;
    }

private:
    unordered_map<int, int> bobPath;
    vector<bool> visited;
    vector<vector<int>> tree;

    // Depth First Search
    bool findBobPath(int sourceNode, int time) {
        // Mark and set time node is reached
        bobPath[sourceNode] = time;
        visited[sourceNode] = true;

        // Destination for Bob is found
        if (sourceNode == 0) {
            return true;
        }

        // Traverse through unvisited nodes
        for (auto adjacentNode : tree[sourceNode]) {
            if (!visited[adjacentNode]) {
                if (findBobPath(adjacentNode, time + 1)) {
                    return true;
                }
            }
        }
        // If node 0 isn't reached, remove current node from path
        bobPath.erase(sourceNode);
        return false;
    }
};