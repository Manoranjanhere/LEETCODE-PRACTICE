class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
	int n = s.size();
	int i=0;
	int j=n-1;
	while(i<n&&s[i]==' ')i++;
	while(j>i&&s[j]==' ')j--;
	if(i>j)return ans;
	ans+=s[i];
	for(int k=i+1;k<=j;k++)
	{
		if(s[k]==' '&&s[k]==s[k-1])continue;		ans+=s[k];	
	}
	vector<int> st;
	st.push_back(-1);
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]==' ')st.push_back(i);
	}
	st.push_back(ans.size());
	for(int i=0;i<st.size()-1;i++)
	{
		reverse(ans.begin()+st[i]+1,ans.begin()+st[i+1]);
	}
	return ans;
    }
};