class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        int j= nums[0];
        if(n==1)return true;
        if(j==0)return false;
       for(int i=1;i<n-1;i++)
       {
            j--;
            j=max(j,nums[i]);
            if(j==0)
            {
                return false;
            }
       }
       return true;
    }
};