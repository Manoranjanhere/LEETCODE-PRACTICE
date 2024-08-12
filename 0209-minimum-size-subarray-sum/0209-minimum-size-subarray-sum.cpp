class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int min=INT_MAX;
        int j=0;
        int n =nums.size();
        for(int i=0;i<n;i++)
        {
            
           
                sum+=nums[i];
               
            
            while(sum>=target)
            {
                 if((i-j)<min)
                {
                    min=i-j;
                }
                sum-=nums[j];
                j++;
            }
           
        }
        return min==INT_MAX?0:min+1;
    }
};