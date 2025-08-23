class Solution {
public:
    int characterReplacement(string s, int k) {
	int n = s.size();
	unordered_map<int,int> mp;
	int c=0;
	int ans =0;
	int ind =0;
	for(int i=0;i<n;i++)
	{
		mp[s[i]]++;
		c=max(c,mp[s[i]]);
		while(i-ind+1-c>k)
		{
			mp[s[ind]]--;
			ind++;
		}
		ans=max(ans,i-ind+1);
	}
	
	return ans;
     }
};