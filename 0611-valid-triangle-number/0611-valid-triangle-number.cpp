class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       int c=0;
       for(int i=n-1;i>=2;i--)
       {
            int left =0;
            int right=i-1;
            while(left<right)
            {
                if(nums[left]+nums[right]>nums[i])
                {
                    c+=(right-left);
                    right--;
                }
                else
                {
                    left++;
                }
            }
       }
       return c;
    }
};