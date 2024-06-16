class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums1;
        int n = nums.size();
       k%=n;
        for(int i=n-k;i<n;i++)
        {
            nums1.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++)
        {
            nums1.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=nums1[i];
        }
    }
};