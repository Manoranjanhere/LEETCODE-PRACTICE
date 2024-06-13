class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
       int r = 0,l=0;
       int sum =0;
       int m = INT_MAX;
       while(r<=n||l<=n)
       {
        if(sum<target&&r<n)
        {
            sum+=nums[r];
            r++;
        }
        else if(sum>=target&&l<n)
        {
            m= min(m,r-l);
            sum-=nums[l];
            l++;
        }
        else
        {
            break;
        }
       }
       return (m==INT_MAX)?0:m;
    }
};