class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>prime(right+1,true);
        int p1=-1;
        int p2=-1;
        int diff=INT_MAX;
        int mp1=-1;
        int mp2=-1;
        eratosthenes(prime,right);
        for(int i=left;i<=right;i++)
        {
            if(prime[i]==true)
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
    void eratosthenes(vector<bool>&prime,int right)
    {
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=right;i++)
        {
            if(prime[i]==true)
            {
                for(int j=i*i;j<=right;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
    }
};