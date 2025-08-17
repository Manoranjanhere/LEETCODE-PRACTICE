class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
	unordered_map<char,int>mp;
	int ind=0;
	int c=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		while(mp[s[i]]>=1)
		{
			mp[s[ind]]--;
			ind++;
			c--;
		}
		mp[s[i]]++;
		c++;
		ans=max(ans,c);
	}
	return ans;
    }
};