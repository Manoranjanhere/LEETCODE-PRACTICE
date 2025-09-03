class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
	unordered_map<char,int> mp2;
	int n1 = s1.size();
	int n2 = s2.size();
    if(n2<n1)return false;
	for(int i=0;i<n1;i++)
	{
		mp1[s1[i]]++;
		mp2[s2[i]]++;
	}
	if(mp1==mp2)return true;
	int ind =0;
	for(int i=n1;i<n2;i++)
	{
		mp2[s2[ind]]--;
		mp2[s2[i]]++;
		if(mp2[s2[ind]]==0)mp2.erase(s2[ind]);
		if(mp1==mp2)
		{
			return true;
		}
		ind++;
	}
	return false;
    }
};