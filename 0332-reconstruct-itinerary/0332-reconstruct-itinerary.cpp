class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string,vector<string>>mp;
        for(auto i:tickets)
        {
            mp[i[0]].push_back(i[1]);
        }
        for( auto& i:mp)
        {
            sort(i.second.rbegin(),i.second.rend());
        }
        stack<string> st;
        st.push("JFK");
        while(!st.empty())
        {
            string curr = st.top();
            if(mp[curr].size()!=0)
            {
                st.push(mp[curr].back());
                mp[curr].pop_back();
            }
            else
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};