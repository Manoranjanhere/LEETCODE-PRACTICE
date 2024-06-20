class Solution {
public:
    bool isPalindrome(int x) {
        int c=x;
        long sum=0;
        if(c<0)return false;
        while(c>0)
        {
            sum=sum*10+c%10;
            c/=10;
        }
        return (x==sum);
    }
};