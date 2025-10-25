class Solution {
public:
    int totalMoney(int n) {
        int k = 7;
        int j=0;
        int sum =0;
        while(n>=7)
        {
            sum+=k*(k+1)/2;
            sum -=j*(j+1)/2;
            k++;
            j++;
            n-=7;
        }
        if(n>0)
        {
            j++;
            while(n)
            {
                sum+=j;
                j++;
                n--;
            }
        }
        return sum;
    }
};