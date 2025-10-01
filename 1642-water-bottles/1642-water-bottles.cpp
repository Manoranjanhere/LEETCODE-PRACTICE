class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        while(numBottles>=numExchange)
        {
            int k = numBottles/numExchange;
            sum+=k;
            numBottles=k+(numBottles%numExchange);
        }
        return sum;
    }
};