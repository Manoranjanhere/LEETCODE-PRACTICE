class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxn= *max_element(nums.begin(),nums.end());
        vector<int> points(maxn+1);
        vector<int> dp(maxn+1);
        for(int num:nums)
        {
            points[num]+=num;
        }
        dp[0]=0;
        dp[1]=points[1];
        for(int i=2;i<=maxn;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+points[i]);
        }
        return dp[maxn];
    }
};