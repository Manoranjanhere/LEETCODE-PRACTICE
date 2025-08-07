class Solution {
public:
    string getHint(string secret, string guess) {
        int ans =0;
	unordered_map<char,int> sec;
	unordered_map<char,int> gue;
	for(int i=0;i<secret.size();i++)
	{
		sec[secret[i]]++;
		gue[guess[i]]++;
		if(secret[i]==guess[i])ans++;
	}
	int st=0;
	for(auto i:sec)
	{
		st+=min(gue[i.first],i.second);
	}
    string final="";
    cout<<st;
    final=to_string(ans)+'A'+to_string(st-ans)+'B';
	return final;
    }
};