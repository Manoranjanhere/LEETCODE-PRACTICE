class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j=0;
        int p=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[j]>prices[i])
            {
                j=i;
                cout<<j<<endl;
            }
            else if(0<prices[i]-prices[j])
            {
                p+=prices[i]-prices[j];
                j=i;
                cout<<p;
            }
        }
        return p;
    }
};