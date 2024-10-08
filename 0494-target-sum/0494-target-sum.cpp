class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int c=0;
        solve(nums,target,c,0);
        return c;
    }
    void solve(vector<int>& nums,int target,int &c,int l)
    {
        if(l==nums.size())
        {
            if(target==0)
            {
                c++;
            }
            return;
        }
       
            solve(nums,target-nums[l],c,l+1);
            solve(nums,target+nums[l],c,l+1);
    }

};