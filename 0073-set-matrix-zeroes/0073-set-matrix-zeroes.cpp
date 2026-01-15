class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> ic;
	unordered_set<int> jc;
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			if(matrix[i][j]==0)
			{
				ic.insert(i);
				jc.insert(j);
			}
		}
	}
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			if(ic.find(i)!=ic.end()||jc.find(j)!=jc.end())matrix[i][j]=0;
		}
	}

    }
};