class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp(n,1);
        vector<int> count(n, 1);   
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]<nums[j])
                {
                    if(dp[j]<1+dp[i])
                    {
                        dp[j]=dp[i]+1;
                        count[j]=count[i];
                    }
                     else if (dp[i] + 1 == dp[j]) 
                     {
                        count[j] += count[i];
                    }
                }
            }
        }
        maxx = *max_element(dp.begin(),dp.end());
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxx)
            {
                c+=count[i];
            }
        }
        return c;
    }
};