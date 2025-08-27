class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>gr(numCourses);
        vector<int> indegree(numCourses);
        for(auto i:prerequisites)
        {
            gr[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        stack<int> st;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                st.push(i);
            }
        }
        while(!st.empty())
        {
            int curr= st.top();
            st.pop();
            for(int i:gr[curr])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    st.push(i);
                }
            }
        }
        for(int i:indegree)
        {
            if(i!=0)return false;
        }
        return true;
    }
};