class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
	int one = words[0].size();
	int total= n*one;
	vector<int> ans;
	if(s.size()<total)return ans;
	unordered_map<string,int> str;
	for(string i:words)
	{
		str[i]++;
	}
	for (int start = 0; start < one; start++) {
	unordered_map<string,int> mp;
	for(int i=start;i+one<=start+total;i+=one)
	{
		string get=s.substr(i,one);
		mp[get]++;
	}
	int j=start;
	if(mp==str)ans.push_back(j);
	while(j+total+one<=s.size())
	{
		string del = s.substr(j,one);
		mp[del]--;
		if(mp[del]==0) mp.erase(del);
		string add= s.substr(j+total,one);
		mp[add]++;
		j+=one;
		if(mp==str)ans.push_back(j);

	}
	}
	return ans;
    }
};