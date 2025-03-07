class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int p1=-1;
        int p2=-1;
        int diff=INT_MAX;
        int mp1=-1;
        int mp2=-1;
        for(int i=left;i<=right;i++)
        {
            if(isprime(i))
            {
                p2=p1;
                p1=i;
            }
            if(p1!=-1&&p2!=-1)
            {
                if(p1-p2<diff)
                {
                    diff=p1-p2;
                    mp1=p1;
                    mp2=p2;
                }
            }
        }
        if(mp1==-1||mp2==-1)
        {
            return {-1,-1};
        }
        else
        {
            return {mp2,mp1};
        }
    }
    bool isprime(int x)
    {
        if(x<2)return false;
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
            {
                return false;
            }
        }
        return true;
    }
};