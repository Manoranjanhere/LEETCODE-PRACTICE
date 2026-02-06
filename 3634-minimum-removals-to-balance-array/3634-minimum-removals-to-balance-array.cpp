class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i =0;
        int best=1;
        for(int j=1;j<n;j++)
        {
            if(nums[i]*1LL*k>=nums[j])
            {
                best=max(best,j-i+1);
            }
            else
            {
                while(i<j&&nums[i]*1ll*k<nums[j])i++;
            }
        }
        return n-best;
    }
};