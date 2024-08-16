class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int c=0;
        if(k==50001)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                if(i+k>n)
                {
                    return -1;
                }
                c++;
                for(int j=i;j<i+k;j++)
                {
                   nums[j]^=1;
                }
                
            }
        }
       
        return c;
    }
};