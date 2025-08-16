class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        if(n<=1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        int right = nums.size()-1;
        while(left<right)
        {
            int mid = left+(right-left)/2;
            if(mid!=0&&mid!=n-1&&nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
            {
                return mid;
            }
            if(nums[mid]>nums[mid+1])
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return -1;
    }
};