class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        stack<vector<pair<int,int>>> st;
        vector<vector<bool>>store(n,vector<bool>(m,false));
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0&&!store[i][j])
                {
                    st.push({{i,j}});
                    store[i][j]=true;
                    int sum=0;
                    while(!st.empty())
                    {
                        auto curr = st.top();
                        st.pop();
                        int f = curr[0].first;
                        int s = curr[0].second;
                        store[f][s]=true;
                        sum+=grid[f][s];
                        if(s<m-1&&grid[f][s+1]!=0&&!store[f][s+1])
                        {
                            st.push({{f,s+1}});
                            store[f][s+1]=true;
                        }
                        if(s>0&&grid[f][s-1]!=0&&!store[f][s-1])
                        {
                            st.push({{f,s-1}});
                            store[f][s-1]=true;
                        }
                        if(f<n-1&&grid[f+1][s]!=0&&!store[f+1][s])
                        {
                            st.push({{f+1,s}});
                            store[f+1][s]=true;
                        }
                        if(f>0&&grid[f-1][s]!=0&&!store[f-1][s])
                        {
                            st.push({{f-1,s}});
                            store[f-1][s]=true;
                        }
                    }
                    ans=max(ans,sum);
                }

            }
        }
        return (ans==INT_MIN)?0:ans;
    }
};