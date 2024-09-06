class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            long long prod=1;
            for(int j=i;j<n;j++)
            {
                prod*=nums[j];
                if(prod<k)
                {
                    c++;
                }
                else
                {
                    break;
                }
            }
        }
        return c;
    }
};