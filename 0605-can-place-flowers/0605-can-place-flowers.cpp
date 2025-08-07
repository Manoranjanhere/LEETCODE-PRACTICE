class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int nf = flowerbed.size();
	int c=0;
	if(nf<0)return c>=n;
	if(nf==1)
	{
		if(flowerbed[0]==1)
		{
			return c>=n;	
		}
		else
		{
			return 1>=n;
		}
	}
	for(int i=0;i<nf;i++)
	{
		if(i==0)
		{
			if(flowerbed[i]==0&&flowerbed[i+1]==0)
			{
				c++;
				flowerbed[i]=1;
			}
		}
		else if(i==nf-1)
		{
			if(flowerbed[i]==0&&flowerbed[i-1]==0)
			{
				c++;
				flowerbed[i]=1;
			}
		}
		else if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0)
		{
			c++;
			flowerbed[i]=1;
		}
	}
	return c>=n;
    }
};