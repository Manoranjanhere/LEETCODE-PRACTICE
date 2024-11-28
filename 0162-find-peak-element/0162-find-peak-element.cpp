class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=nums.size()-1;
        int mid=0;
        while(l<r)
        {
            mid = (l+r)/2;
            if(mid>0&&mid<n&&nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
            {
                return mid;
            }
            if(nums[mid]>nums[mid+1])
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return r;
    }
};