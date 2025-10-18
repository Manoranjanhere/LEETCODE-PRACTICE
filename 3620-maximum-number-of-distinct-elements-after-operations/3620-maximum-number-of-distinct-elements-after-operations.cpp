class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n==0)return 0;
        int prev = nums[0]-k;
        int c=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]+k>prev)
            {
                c++;
                prev = max(prev+1,nums[i]-k);
            }
        }
        return c;
    }
};