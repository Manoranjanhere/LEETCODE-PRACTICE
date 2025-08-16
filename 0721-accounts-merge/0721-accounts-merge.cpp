class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>>graph;
        unordered_map<string,string> emailToName;

        for(auto &acc:accounts)
        {
            string name = acc[0];
            for(int i=1;i<acc.size();i++)
            {
                emailToName[acc[i]] = name;
                if(i==1)continue;
                graph[acc[i]].push_back(acc[i-1]);
                graph[acc[i-1]].push_back(acc[i]);
            }
        }
        unordered_set<string> visited;
        vector<vector<string>>res;

        for(auto &p : emailToName)
        {
            string email = p.first;
            if(visited.count(email))continue;
            vector<string> emails;
            stack<string> st;
            st.push(email);
            visited.insert(email);

            while(!st.empty())
            {
                string cur = st.top();st.pop();
                emails.push_back(cur);
                for(auto &nbr:graph[cur])
                {
                    if(!visited.count(nbr))
                    {
                        visited.insert(nbr);
                        st.push(nbr);
                    }
                }
            }
            sort(emails.begin(),emails.end());
            emails.insert(emails.begin(),emailToName[email]);
            res.push_back(emails);
        }
        return res;
    }
};