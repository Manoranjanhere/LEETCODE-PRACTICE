class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
	vector<string> ans(numRows,"");
	if(numRows<=1||n<=1)return s;
	bool dir =true;
	ans[0]+=s[0];
	int i=1;
	while(i<n)
	{	
		if(dir)
		{
			for(int j=1;j<numRows;j++)
			{
				if(i==n)break;
				ans[j]+=s[i];
				i++;
			}
		}
		else
		{
			for(int j=numRows-2;j>=0;j--)
			{
			if(i==n)break;
			ans[j]+=s[i];
			i++;
			}
		}
		dir=!dir;
	}
	string final="";
	for(string i:ans)
	{
		final+=i;
	}
	return final;
    }
};