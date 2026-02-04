class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zc=0;
        int zi;
        int mul=1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zc++;
                zi=i;
            }
            else
            {
                mul*=nums[i];
            }
        }
        if(zc>1)return ans;
        if(zc==1){ans[zi]=mul;return ans;}
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=mul/nums[i];
        }
        return ans;
    }
};