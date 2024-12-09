class Solution {
public:
    bool possible(int mid,vector<int> nums,int maxops)
    {
        int ops=0;
        if(mid==0)return false;
        for(int i:nums)
        {

            ops+=(int)ceil((double)i/mid)-1;
            if(ops>maxops)
            {
                return false;
            }
        }
            return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int l=0;
        int r = *max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(possible(mid,nums,maxOperations))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};