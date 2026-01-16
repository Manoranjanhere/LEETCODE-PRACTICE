class Solution {
public:
    bool isHappy(int n) {
        int slow=n;
        int fast= next(n);
        while(fast!=1&&slow!=fast)
        {
            slow=next(slow);
            fast=next(next(fast));
        }
        return fast==1;
    }
    int next(int n)
    {
        int sum =0;
        while(n>0)
        {
            int rem= n%10;
            sum+=rem*rem;
            n/=10;
        }
        return sum;
    }
};