class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)return x;
        if(n==0)return 1;
        if(n==1)return x;
        long k =n;
        if(n<0){ x=1/x;k*=-1;}
        double res=1;
        while(k>0)
        {
            if(k%2==0)
            {
                k/=2;
                x*=x;
            }
            k--;
            res*=x;
        }
        return res;
    }
};