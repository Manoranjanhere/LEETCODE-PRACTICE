class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int n = piles.size();
        if(n==h)return r;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            long long c=0;
            for(int i=0;i<n;i++)
            {
                if(piles[i]%mid==0)
                {
                    c+=piles[i]/mid;
                }
                else
                {
                    c+=piles[i]/mid+1;
                }
            }
            if(c>h)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l;
    }
};