class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int extra = 0;
	string final = s;
	int n = indices.size();
	vector<pair<int,int>> st;
	for(int i=0;i<n;i++)
	{
		st.push_back({indices[i],i});
	}
	sort(st.begin(),st.end());
	for(auto [ind,i]:st)
	{
		if(s.substr(ind,sources[i].size())==sources[i])
		{
			final.replace(ind+extra,sources[i].size(),targets[i]);
			extra+=targets[i].size()-sources[i].size();
		}
	}
	return final;
    }
};