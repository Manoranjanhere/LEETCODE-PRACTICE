class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dp;
        return solve(s,wordDict,dp);
    }
    bool solve(string s, vector<string>& wordDict,unordered_map<string,bool>& dp)
    {
        if(s=="")
        {
            return true;
        }
        if(dp.find(s)!=dp.end())
        {
            return dp[s];
        }
        for(int i=0;i<=s.length();i++)
        {
            string prefix = s.substr(0,i);
            if(find(wordDict.begin(),wordDict.end(),prefix)!=wordDict.end())
            {
                if(solve(s.substr(i),wordDict,dp))
                {
                    return dp[s]=true;
                }
            }
        }
            return dp[s]=false;
    }
};