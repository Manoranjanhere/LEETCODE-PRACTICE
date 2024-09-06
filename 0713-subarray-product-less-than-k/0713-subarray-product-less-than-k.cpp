class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int c=0;
        int s=0;
        long long prod=1;
        for(int i=0;i<n;i++)
        {
            prod*=nums[i];
            while(prod>=k&&s<=i)
            {
                prod/=nums[s];
                s++;
            }
            c += (i - s + 1);
        }
        return c;
    }
};