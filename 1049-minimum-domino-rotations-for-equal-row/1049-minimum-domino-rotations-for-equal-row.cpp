class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
	int cand1=tops[0];
	int cand2=bottoms[0];
	int top=  solve(tops,bottoms,cand1);
	int bottom=solve(tops,bottoms,cand2);
	int ans = min(top,bottom);
	return (ans==INT_MAX)?-1:ans;
	
      }
	int solve(vector<int>& tops, vector<int>& bottoms,int x)
	{
		int top=0;
		int bottom=0;
		for(int i=0;i<tops.size();i++)
		{
		if(x!=tops[i]&&x!=bottoms[i])
		{
			return INT_MAX;
		}
		else if(x!=tops[i])top++;
		else if(x!=bottoms[i])bottom++;
		}
	return min(top,bottom);
	}
};