class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return true;
        int s=nums[0];
        if(s==n-1)return true;
        if(s==0)return false;
        for(int i=1;i<n;i++)
        {
            s=max(s-1,nums[i]);
            if(s==0)return false;
            if(nums[i]+i>=n-1)return true;
        }
        return false;
    }
};