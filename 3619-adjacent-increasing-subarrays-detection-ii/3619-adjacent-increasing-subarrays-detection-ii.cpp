class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                dp[i]=dp[i-1]+1;
            }
        }
        int l=1;
        int r=n/2;
        int k = 1;
        while(l<=r)
        {
            int mid= (l+r)/2;
            bool got = false;
            for(int i=0;i+2*mid<=n;i++)
            {
                if(dp[i+mid-1]>=mid&&dp[i+mid*2-1]>=mid)
                {
                    got=true;
                    k=max(k,mid);
                    l=mid+1;
                    break;
                }
            }
            if(!got)
            {
                r=mid-1;
            }
        }
        return k;
    }
};