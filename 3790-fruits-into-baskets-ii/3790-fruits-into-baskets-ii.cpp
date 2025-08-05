class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
	int m = baskets.size();
	vector<int>vis(m,0);
	int c=0;
	for(int i=0;i<n;i++)
	{
		bool d=false;
		for(int j=0;j<m;j++)
		{
			if(fruits[i]<=baskets[j]&&vis[j]==0)
			{
				d=true;
				vis[j]=1;
				break;
			}

		}
		if(!d)c++;
	}
	return c;
    }
};