class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1i=0;
        int s2i=0;
        if(s1.size()+s2.size()!=s3.size())return false;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1i,s2i,s1,s2,s3,dp);
    }
    bool solve(int s1i,int s2i,string s1, string s2, string s3,vector<vector<int>>&dp)
    {
            int ind = s1i+s2i;
            if(ind==s3.size())
            {
                return(s1i==s1.size()&&s2i==s2.size());
            }
            if(dp[s1i][s2i]!=-1)return dp[s1i][s2i];
            bool ans =false;
            if(s1i<s1.size()&&s1[s1i]==s3[ind])
            {
                ans= ans||solve(s1i+1,s2i,s1,s2,s3,dp);
            }
            if(s2i<s2.size()&&s2[s2i]==s3[ind])
            {
                ans= ans||solve(s1i,s2i+1,s1,s2,s3,dp);
            }
            return dp[s1i][s2i]=ans;
        }
};