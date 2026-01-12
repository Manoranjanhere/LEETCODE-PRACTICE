class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	int n = strs[0].size();
	for(int i=1;i<strs.size();i++)
	{
		int j=0;
		while(j<n&&strs[0][j]==strs[i][j])j++;
		n=j;
	}
	return strs[0].substr(0,n);
        
    }
};