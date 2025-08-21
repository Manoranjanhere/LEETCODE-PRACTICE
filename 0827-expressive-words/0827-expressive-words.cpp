class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
    	int n = s.size();
	int ans =0;
	for(string word:words)
	{
		int ind=0;
		bool yes=true;
		for(int i=0;i<n;i++)
		{
			if(word[ind]!=s[i])
			{
				if((i>=1&&i<n-1&&s[i]==s[i-1]&&s[i]==s[i+1])||(i>=2&&s[i]==s[i-1]&&s[i]==s[i-2]))
				{
					continue;
				}
				else
				{
				yes=false;
				break;
				}
			}
			else
			{
				ind++;
			}
		}
		if(yes&&ind==word.size())
		{
			ans++;
		}
	}
	return ans;
}
};