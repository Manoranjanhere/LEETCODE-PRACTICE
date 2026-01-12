class Solution {
public:
    string convert(string s, int numRows) {
	int n=s.size();
	if(n<=1||numRows<=1)return s;
        vector<string> st(numRows);
	int i=1;
	st[0]+=s[0];
	while(i<n)
	{
		int j=1;
		while(i<n&&j<numRows)
		{
			st[j]+=s[i];
			j++;
			i++;
		}
		j-=2;
		while(i<n&&j>=0)
		{
			st[j]+=s[i];
			j--;
			i++;
		}
		
	}
	string ans ="";
	for(int i=0;i<numRows;i++)
	{
		ans+=st[i];
	}
	return ans;
    }
};