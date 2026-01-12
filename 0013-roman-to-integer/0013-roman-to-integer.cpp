class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
	mp['M']=1000;
	mp['D']=500;
	mp['C']=100;
	mp['L']=50;
	mp['X']=10;
	mp['V']=5;
	mp['I']=1;
	int sum = 0;
	int n = s.size();
    if(n==1)return mp[s[0]];
	for(int i=0;i<n-1;i++)
	{
		if(mp[s[i]]>=mp[s[i+1]])
		{
			sum+=mp[s[i+1]];
			if(i==0)sum+=mp[s[i]];
		}
		else
		{
			sum+=mp[s[i+1]]-mp[s[i]];			if(i!=0)sum-=mp[s[i]];	
		}
	}
	return sum;
    }
};
