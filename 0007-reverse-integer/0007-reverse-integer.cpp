class Solution {                      
public:
    int reverse(int x) {
        long sum =0;
        while(x)
        {
            sum=sum*10+x%10;
            x/=10;
        }
        if(sum>INT_MAX||sum<INT_MIN)return 0;
        return sum;
    }
}; 