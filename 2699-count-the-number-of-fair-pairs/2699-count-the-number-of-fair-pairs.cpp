class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int ans =0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return getmoney(nums,upper+1)-getmoney(nums,lower);
    }
    long long getmoney(vector<int>& nums, int val)
    {
        int left=0;
        long long res=0;
        int right= nums.size()-1;
        while(left<=right)
        {
            if(nums[left]+nums[right]<val)
            {
                res+=right-left;
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};