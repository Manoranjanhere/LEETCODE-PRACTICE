class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr=0;
        int maxx=nums[0];
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            curr = max(curr,nums[i]);
            maxx=max(maxx,curr);
        }
        return maxx;
    }
};