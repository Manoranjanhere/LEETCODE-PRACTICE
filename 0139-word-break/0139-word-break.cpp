class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1);
        unordered_set<string> st;
        for(string i:wordDict)st.insert(i);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(dp[i]==1&&st.find(s.substr(i,j-i+1))!=st.end())dp[j+1]=1;
            }
        }
        return dp[n];
    }
};