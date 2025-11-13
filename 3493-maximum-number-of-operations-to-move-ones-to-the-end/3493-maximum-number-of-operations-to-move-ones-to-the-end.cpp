class Solution {
public:
    int maxOperations(string s) {
        int o=0;
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')o++;
		if(s[i]=='0'){
			ans+=o;
			o++;
			while(i<s.size()&&s[i]=='0')
			{
				i++;
			}
        }
	}
	return ans;

    }
};