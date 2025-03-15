class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minr=1;
        int maxr=*max_element(nums.begin(),nums.end());
        int total= nums.size();

        while(minr<maxr)
        {
            int mid = (minr+maxr)/2;
            int poss=0;
            for(int index=0;index<total;++index)
            {
                if(nums[index]<=mid)
                {
                    poss+=1;
                    index++;
                }
            }
            if(poss>=k)
            {
                maxr=mid;
            }
            else
            {
                minr =mid+1;
            }
        }
        return minr;
    }
};