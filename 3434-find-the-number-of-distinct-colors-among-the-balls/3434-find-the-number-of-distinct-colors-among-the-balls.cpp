class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> un1;
        unordered_map<int,int> mp;
        vector<int> ans;
        int c=0;
        for(int i=0;i<queries.size();i++)
        {
            if(mp.find(queries[i][0])==mp.end()&&un1.find(queries[i][1])==un1.end())
            {
                c++;
                mp[queries[i][0]]=queries[i][1];
                un1[queries[i][1]]++;
                
            }
            else if(mp.find(queries[i][0])!=mp.end()&&un1.find(queries[i][1])==un1.end())
            {
                un1[mp[queries[i][0]]]--;
                if(un1[mp[queries[i][0]]]==0)
                {
                    un1.erase(mp[queries[i][0]]);
                }
                else
                {
                    c++;
                }
                mp[queries[i][0]]=queries[i][1];
                un1[queries[i][1]]++;
            }
            else if(mp.find(queries[i][0])==mp.end()&&un1.find(queries[i][1])!=un1.end())
            {
                mp[queries[i][0]]=queries[i][1];
                un1[queries[i][1]]++;
            }
            else
            {
                if(mp[queries[i][0]]!=queries[i][1])
                {
                    
                    un1[mp[queries[i][0]]]--;
                    if(un1[mp[queries[i][0]]]==0)
                    {
                        c--;
                        un1.erase(mp[queries[i][0]]);
                    }
                    mp[queries[i][0]]=queries[i][1];
                    un1[mp[queries[i][0]]]++;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};