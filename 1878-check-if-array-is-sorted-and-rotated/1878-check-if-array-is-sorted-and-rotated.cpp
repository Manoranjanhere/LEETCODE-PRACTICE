class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(c==0&&nums[i]<nums[i-1])
            {
                
                    c++;
                    if(nums[i]>nums[0])
                    {
                        return false;
                    }
            }
            else if(c==1&&(nums[i]<nums[i-1]||nums[0]<nums[i]))
            {
                return false;
            }
        }
        return true;
    }
};