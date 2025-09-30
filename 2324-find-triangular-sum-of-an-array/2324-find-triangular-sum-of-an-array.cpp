class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n)
        {
            if(n==1)return nums[0];
            n-=1;
            for(int i=0;i<n;i++)
            {
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }
        return 0;
    }
};