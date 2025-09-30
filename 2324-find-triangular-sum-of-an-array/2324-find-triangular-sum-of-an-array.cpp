class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n)
        {
            if(n==1)return nums[0];
            n-=1;
            vector<int> new_nums(n);
            for(int i=0;i<n;i++)
            {
                new_nums[i]=(nums[i]+nums[i+1])%10;
            }
            nums=new_nums;
        }
        return 0;
    }
};