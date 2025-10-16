class Solution {
public:
        vector<int> parent;
        vector<int> rank;
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        parent= vector<int>(n,0);
        rank = vector<int>(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        unordered_set<int> st;
        for(auto i:edges)
        {
            parent[i[1]]=i[0];
        }
        for(auto i:edges)
        {
            int k = find(i[0]);
            st.insert(k);
        }
        vector<int> ans;
        for(int i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
};