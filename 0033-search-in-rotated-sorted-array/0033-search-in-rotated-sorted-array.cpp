class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l= 0;
        int first =l;
        int r= nums.size()-1;
        int last =r;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>nums[last])
            {
                if(nums[mid]>target&&nums[last]<target)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else if(nums[mid]<nums[last]&&nums[mid]<target&&nums[last]>=target)
            {
                l=mid+1;
            }
            else 
            {
                r=mid-1;
            }
        }
        return -1;
    }
};