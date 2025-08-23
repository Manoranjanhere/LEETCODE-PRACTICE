class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)return 0;
       int minn = prices[0];
       int profit =0;
       for(int i=1;i<n;i++)
       {
            minn=min(minn,prices[i]);
            profit=max(profit,prices[i]-minn);
       }
        return profit;
    }
};