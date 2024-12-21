class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         if(n<2)return 1;
         int componentCount =0;
         vector<vector<int>> graph(n);
         vector<int> inDegree(n,0);

         for(const auto& edge :edges)
         {
            int node1 =edge[0];
            int node2 = edge[1];
            graph[node2].push_back(node1);
            graph[node1].push_back(node2);
            inDegree[node1]++;
            inDegree[node2]++;
         }
         vector<long long> longValues(values.begin(),values.end());
         queue<int> queue;
         for(int node = 0;node<n;node++)
         {
            if(inDegree[node]==1)
            {
                queue.push(node);
            }
         }
         while(!queue.empty())
         {
            int currentNode = queue.front();
            queue.pop();
            inDegree[currentNode]--;
            long long addValue=0;
            if(longValues[currentNode]%k==0)
            {
                componentCount++;
            }
            else
            {
                addValue=longValues[currentNode];
            }
            for(int neighbourNode:graph[currentNode])
            {
                if(inDegree[neighbourNode]==0)
                {
                    continue;
                }
                inDegree[neighbourNode]--;
                longValues[neighbourNode]+=addValue;
                if(inDegree[neighbourNode]==1)
                {
                    queue.push(neighbourNode);
                }
            }
         }
         return componentCount;
    }
};