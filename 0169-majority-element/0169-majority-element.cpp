class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int c=0;
        for(int i:nums)
        {
            if(i==maj)c++;
            else
            {
                c--;
                if(c==0)
                {
                    maj=i;
                    c=1;
                }
            }
        }
        return maj;
    }
};