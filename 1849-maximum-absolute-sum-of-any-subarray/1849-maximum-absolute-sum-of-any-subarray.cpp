class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum;
        prefix_sum.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            prefix_sum.push_back(nums[i]+prefix_sum[i-1]);
        }
        int last_pos=0;
        int last_neg=0;
        int sum=0;
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {
           sum = prefix_sum[i];
            if(sum>=0)
            {
                last_pos=max(last_pos,sum);
                sum-=last_neg;
                ans=max(ans,abs(sum));
            }
            else
            {
                last_neg=min(last_neg,sum);
                sum-=last_pos;
                ans=max(ans,abs(sum));
            }
        }
        return ans;
    }
};