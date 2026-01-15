class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0;
	int right=matrix[0].size()-1;
	int top=0;
	int bottom=matrix.size()-1;
	vector<int> ans;
	while(left<=right&&top<=bottom)
	{
		int i=left;
		while(i<=right)
		{
			ans.push_back(matrix[top][i]);
			i++;
		}
		top++;
		i=top;
		while(i<=bottom)
		{
			ans.push_back(matrix[i][right]);
			i++;
		}
		right--;
		i=right;
		while(top<=bottom&&i>=left)
		{
			ans.push_back(matrix[bottom][i]);
			i--;
		}
		bottom--;
		i=bottom;
		while(left<=right&&top<=i)
		{
			ans.push_back(matrix[i][left]);
			i--;
		}
        left++;
	}
	return ans;
    }
};