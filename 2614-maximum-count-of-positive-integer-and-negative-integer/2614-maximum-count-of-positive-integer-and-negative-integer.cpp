class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p=0;
        int n=0;
        for(int num:nums)
        {
            if(num>0)
            {
                p++;
            }
            else if(num<0)
            {
                n++;
            }
        }
        return max(n,p);
    }
};