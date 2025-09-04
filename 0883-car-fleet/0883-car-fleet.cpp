class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        int n = position.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.rbegin(),vec.rend());
        stack<float> st;
        for(auto c:vec)
        {
            float time = (target-c.first)/(float)c.second;
            if(!st.empty()&&time<=st.top())continue;
            st.push(time);
        }
        return st.size();
    }
};