struct Triple {
    int first;
    int second;
    int third;
};
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
	int m =  matrix[0].size();
    int ans =0;
	vector<vector<Triple>> dp(n,vector<Triple>(m,{0,0,0}));
    if(matrix[0][0]=='1')
    {
        ans=1;
        dp[0][0]={1,1,1};
    }
    for(int i=1;i<n;i++)
    {
        if(matrix[i][0]=='1')
        {
            ans=1;
            dp[i][0].first=dp[i-1][0].first+1;
            dp[i][0].second=1;
            dp[i][0].third=1;
        }    
    }
    for(int i=1;i<m;i++)
    {
        if(matrix[0][i]=='1')
        {
            ans=1;
            dp[0][i].second=dp[0][i-1].second+1;
            dp[0][i].first=1;
            dp[0][i].third=1;
        }    
    }
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(matrix[i][j]=='1')
			{
				dp[i][j].first=min({dp[i-1][j].first,dp[i][j-1].second,dp[i-1][j-1].third})+1;
                dp[i][j].second=min({dp[i-1][j].first,dp[i][j-1].second,dp[i-1][j-1].third})+1;
                dp[i][j].third=min({dp[i-1][j].first,dp[i][j-1].second,dp[i-1][j-1].third})+1;
				ans=max(ans,min({dp[i][j].first,dp[i][j].second,dp[i][j].third}));
			}
		}
	}
	return ans*ans;
    }
};