class Solution {
public:
    bool checkPowersOfThree(int n) {
        int k=0;
        while(pow(3,k)<=n)
        {
            k++;
        }
        if(k>0)
        {
            k--;
        }
        n-=pow(3,k);
        if(n==0)
        {
            return true;
        }
        k--;
        while(k>=0)
        {
            if(pow(3,k)<=n)
            {
                n-=pow(3,k);
            }
            k--;
            if(n==0)
            {
                return true;
            }
        }
        return false;
    }
};