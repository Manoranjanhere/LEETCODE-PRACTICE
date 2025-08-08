class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    int n = s.size();
	unordered_map<string,int> mp;
	vector<string> ans;
	for(int i=0;i+10<=n;i++)
	{
		string k = s.substr(i,10);
		mp[k]++;
	}
	for(auto i:mp)
	{
		if(i.second>=2)
		{
			ans.push_back(i.first);
		}
	}
	return ans;
    }
};