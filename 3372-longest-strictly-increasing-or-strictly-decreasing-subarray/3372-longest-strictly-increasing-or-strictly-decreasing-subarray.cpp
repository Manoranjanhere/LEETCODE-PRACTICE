class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int dec=1;
        int store1=1;
        int store2=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                inc++;
                dec=1;
            }
            else if(nums[i]<nums[i-1])
            {
                dec++;
                inc=1;
            }
            else
            {
                dec=1;
                inc=1;
            }
            store1=max(store1,inc);
            store2=max(store2,dec);
        }
        return max(store1,store2);
    }
};