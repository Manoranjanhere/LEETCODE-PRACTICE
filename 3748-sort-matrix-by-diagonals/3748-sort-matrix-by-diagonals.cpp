class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
	int m = grid[0].size();
	int i=n-1;
	int j=0;
	while(i>=0)
	{
		vector<int> ans;
		int previ=i;
		int prevj=j;
		while(i<n)
		{
			ans.push_back(grid[i][j]);
			i++;
			j++;
		}
		sort(ans.rbegin(),ans.rend());
		i=previ;
		j=prevj;
		int ind=0;
		while(i<n)
 		{
 			grid[i][j]=ans[ind];
 			i++;
 			j++;
			ind++;
 		}
		i=previ-1;
		j=0;
	}
	i=0;
	j=1;
	while(j<n)
	{
		vector<int> ans;
		int previ=i;
 		int prevj=j;
 		while(j<n)
 		{
 			ans.push_back(grid[i][j]);
 			i++;
 			j++;
 		}
 		sort(ans.begin(),ans.end());
 		i=previ;
 		j=prevj;
 		int ind=0;
 		while(j<n)
 		{
 			grid[i][j]=ans[ind];
 			i++;
 			j++;
 			ind++;
 		}
 		i=0;
 		j=prevj+1;
	}
	return grid;
    }
};