class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        q.push(0);
        vector<vector<int>> ans;
        vector<int> st;
        solve(q,ans,st,graph);
        return ans;
    }
    void solve(queue<int>& q,vector<vector<int>>& ans,vector<int>& st,vector<vector<int>>& graph)
    {
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            st.push_back(curr);
            if(curr==graph.size()-1)
            {
                ans.push_back(st);
                st.pop_back();
                return;
            }
            for(int i:graph[curr])
            {
                q.push(i);
                solve(q,ans,st,graph);
            }
            st.pop_back();
        }
    }
};