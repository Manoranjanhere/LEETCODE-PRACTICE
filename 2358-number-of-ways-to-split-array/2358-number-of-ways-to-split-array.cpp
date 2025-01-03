class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int c=0;
        int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int start=0;
        for(int i=0;i<n-1;i++)
        {
            start+=nums[i];
            sum-=nums[i];
            if(start>=sum)
            {
                c++;
            }
        }
        return c;
    }
};