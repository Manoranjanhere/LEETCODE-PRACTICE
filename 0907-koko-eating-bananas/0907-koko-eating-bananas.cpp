class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int l=1;
    int r=*max_element(piles.begin(),piles.end());
    while(l<r)
    {
        int sum=0;
        int mid = (l+r)/2;
        for(int pile:piles)
            {
                 sum+=ceil((double)pile/mid);
            }
        if(sum<=h)
            {
                r = mid;
            }
        else
            {
                l =mid+1;
            }
    }
    return l;
    }
};