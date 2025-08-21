class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
	int cand1=tops[0];
	int cand2=bottoms[0];	
		int top=0;
		int bottom=0;
		for(int i=0;i<tops.size();i++)
		{
		if(cand1!=tops[i]&&cand1!=bottoms[i])
		{
			top=INT_MAX;
            bottom=INT_MAX;
            break;
		}
		else if(cand1!=tops[i])top++;
		else if(cand1!=bottoms[i])bottom++;
		}
	int ans1 = min(top,bottom);
		top=0;
		bottom=0;
		for(int i=0;i<tops.size();i++)
		{
		if(cand2!=tops[i]&&cand2!=bottoms[i])
		{
			top=INT_MAX;
            bottom=INT_MAX;
            break;
		}
		else if(cand2!=tops[i])top++;
		else if(cand2!=bottoms[i])bottom++;
		}
	int ans2 = min(top,bottom);
	int ans = min(ans1,ans2);
	return (ans==INT_MAX)?-1:ans;

	}
};