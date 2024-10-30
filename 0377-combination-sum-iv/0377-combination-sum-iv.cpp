class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int c=0;
        vector<int> dp(target+1,-1);
        solve(nums,target,0,c,dp);
        return c;
    }
    void solve(vector<int>& nums,int target,int sum,int & c,vector<int>& dp)
    {
        if(sum==target)
        {
            c++;
            return;
        }
        if(sum>target)
        {
            return;
        }
        if(dp[sum]!=-1)
        {
            c+=dp[sum];
            return;
        }
        int inc = c;
        for(int i=0;i<nums.size();i++)
        {
            solve(nums,target,sum+nums[i],c,dp);
        }
        dp[sum]=c-inc;
    }
};