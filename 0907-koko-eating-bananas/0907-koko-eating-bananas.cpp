class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int max =0;
    int n = piles.size();
    for(int i=0;i<n;i++)
    {
        if(piles[i]>max)
        {
            max=piles[i];
        }
    }
    int l=1;
    int r = max;
    while(l<r)
    {
        int mid = (l+r)/2;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=ceil((double)piles[i]/mid);
        }
        if(sum>h)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return l;
    }
    
};