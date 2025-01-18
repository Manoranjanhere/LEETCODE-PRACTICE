class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n==0)return 0;
         if(n==1) return nums[0];
        vector<int> s1;
        vector<int> s2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                s1.push_back(nums[i]);
            }
            if(i!=n-1)
            {
                s2.push_back(nums[i]);
            }
        }
        
        return max(solve(s1),solve(s2));
    }
    int solve(vector<int>& nums)
    {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};