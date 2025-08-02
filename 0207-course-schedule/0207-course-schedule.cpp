class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> gr(numCourses);
         vector<int> indegree(numCourses,0);
         for(auto i:prerequisites)
         {
            indegree[i[0]]++;
            gr[i[1]].push_back(i[0]);
         }
         queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(int neighbour:gr[curr])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }
        for(int i:indegree)
        {
            if(i!=0)
            {
                return false;
            }
        }
        return true;
    }
};