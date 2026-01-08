class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int mp=0;
		int mn=INT_MAX;
		for(int i:prices)
		{
			mn=min(i,mn);
			mp=max(mp,i-mn);
		}
		return mp;
            }
};