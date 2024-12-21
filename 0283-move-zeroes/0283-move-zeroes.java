class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int in =0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                int temp=nums[in];
                nums[in++]=nums[i];
                nums[i]=temp;
            }
        }
    }
}