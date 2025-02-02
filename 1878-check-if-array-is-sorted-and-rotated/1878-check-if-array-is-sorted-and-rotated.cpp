class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        int n = nums.size();
        int rot=0;
        int ind=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                if(c==0)
                {
                    rot= nums[0];
                    ind=i;
                    c++;
                }
                else
                {
                    return false;
                }
            }
        }
        if(rot!=0)
        {
            for(int i=ind;i<n;i++)
            {
                if(rot<nums[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};