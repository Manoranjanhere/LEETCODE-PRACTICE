class Solution {
public:
    int smallestNumber(int n) {
        while((n&(n+1))!=0)
        {
            n++;
        }
        return n;
    }
};