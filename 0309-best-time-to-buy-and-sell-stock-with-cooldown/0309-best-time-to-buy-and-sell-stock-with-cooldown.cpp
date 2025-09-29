class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy = INT_MIN;
       int sell = 0;
       int prev_sell =0;
       int prev_buy;
       for(int price:prices)
       {
        prev_buy = buy;
        buy= max(buy,prev_sell-price);
        prev_sell=sell;
        sell = max(prev_buy+price,sell);
       } 
       return sell;
    }
};