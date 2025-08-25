class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
	int n = mat.size();
	int m = mat[0].size();
	vector<int> ans;
	int i=0;int j=0;
	bool dir =true;
	while(ans.size()<m*n)
	{
		while(i>=0&&i<n&&j>=0&&j<m)
		{
			if(dir)
			{
				ans.push_back(mat[i][j]);
			i--;
			j++;
			}
			else
			{
			ans.push_back(mat[i][j]);
			i++;
			j--;
			}
		}
		if(i==-1&&j<m)
		{
			i=0;
		}
		else if(j==-1&&i<n)
		{
			j=0;
		}
		else if(i>=n)
		{
			i=n-1;
			j+=2;
		}
		else if(j>=m)
		{
			j=m-1;
			i+=2;
		}
		dir=!dir;
	}
	return ans;
}
};