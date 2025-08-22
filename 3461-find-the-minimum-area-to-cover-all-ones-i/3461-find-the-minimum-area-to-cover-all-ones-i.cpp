class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
	int top =0;
	int bottom=-1;
	int left=0;
	int right=0;
	int n = grid.size();
	int m = grid[0].size();
    bool got=false;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]==1)
			{
				top=i;
                got=true;
				break;
			}
		}
        if(got)
        {
            break;
        }
	}
    got=false;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]==1)
			{
                got=true;
				bottom=i;
				break;
			}
		}
        if(got)
        {
            break;
        }
	}
    got=false;
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(grid[i][j]==1)
			{
                got=true;
				left=j;
				break;
			}
		}
        if(got)
        {
            break;
        }
	}
    got=false;
	for(int j=m-1;j>=0;j--)
	{
		for(int i=0;i<n;i++)
		{
			if(grid[i][j]==1)
			{
                got=true;
				right=j;
				break;
			}
		}
        if(got)
        {
            break;
        }
	}
    if(bottom==-1)return 0;
	int ans = (right-left+1)*(bottom-top+1);
	return ans;
    }
};