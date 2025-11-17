class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int s= -k-1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                if(i-s<=k)return false;
                s=i;
            }
        }
        return true;
    }
};