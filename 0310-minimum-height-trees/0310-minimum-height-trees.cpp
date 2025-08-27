class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> st;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                st.push(i);
            }
        }
        int rem =n;
        while(rem>2)
        {
            int sz = st.size();
            rem-=sz;
            for(int i=0;i<sz;i++)
            {
                int curr= st.front();
                st.pop();
                for(int i:adj[curr])
                {
                    degree[i]--;
                    if(degree[i]==1)
                    {
                        st.push(i);
                    }
                }

            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.front());
            st.pop();
        }
        return ans;
    }
};