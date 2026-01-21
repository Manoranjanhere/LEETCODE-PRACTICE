class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        long long rev=0;
        while(n>0)
        {
            rev=rev*10+n%10;
            n/=10;
        }
        return(rev==x);
    }
};