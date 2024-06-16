class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size();
       int i=0;
       int j=0;     
        j=nums[0];
        if(n==1)return true;
        if(j==0)return false;
                while(j)
                {
                    --j;
                    ++i;
                    if(i>=n-1)
                    {
                        return true;
                    }
                    if(j<nums[i])
                    {
                        j=nums[i];
                    }
                    if(j==0)
                    {
                        return false;
                    }
                }
                return false;
    }
};