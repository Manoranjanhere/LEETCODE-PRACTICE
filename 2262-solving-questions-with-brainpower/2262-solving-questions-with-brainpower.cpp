class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return solve(questions,0,dp);
    }
    long long solve(vector<vector<int>>& questions, int ind,vector<long long>&dp)
    {
        if(ind>=questions.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        long long nottake = solve(questions,ind+1,dp);
        long long take = questions[ind][0]+solve(questions,ind+questions[ind][1]+1,dp);
        return dp[ind]= max(nottake,take);
    }
};