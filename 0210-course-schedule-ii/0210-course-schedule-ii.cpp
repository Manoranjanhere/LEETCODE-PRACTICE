class Solution {
public:
bool dfs(int node,map<int,vector<int>>&mp,vector<int>&vis,vector<int>& path,vector<int>& res)
{
    vis[node]=1;
    path[node]=1;
    for(auto neighbour:mp[node])
    {
        if(!vis[neighbour])
        {
            if(dfs(neighbour,mp,vis,path,res))
            {
                return true;
            }
        }
        else if(path[neighbour])
        {
            return true;
        }

    }
    path[node]=0;
    res.push_back(node);
    return false;

}
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        map<int,vector<int>>mp;
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        vector<int> res;
        int n = p.size();
        for(int i=0;i<n;i++)
        {
            mp[p[i][0]].push_back(p[i][1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,mp,vis,path,res))
                {
                    return {};
                }
            }
        }
        return res;
    }
};