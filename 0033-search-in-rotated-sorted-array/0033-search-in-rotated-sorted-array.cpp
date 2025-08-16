class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int n = nums.size()-1;
        int right = n;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid]==target)return mid;
            if(nums[left]<=nums[mid])
            {
                if(nums[left]<=target&&target<nums[mid])
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            else if(nums[mid]<=nums[right])
            {
                if(target>nums[mid]&&target<=nums[right])
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};