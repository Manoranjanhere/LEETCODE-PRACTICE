class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<int> dp(n,1);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(pairs[i][1]<pairs[j][0])
                {
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};