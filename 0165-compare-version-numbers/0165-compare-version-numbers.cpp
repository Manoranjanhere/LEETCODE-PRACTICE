class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> k1;
	vector<int> k2;
	int n = version1.size();
	int m = version2.size();
	for(int i=0;i<n;i++)
	{
		if(version1[i]=='.')
		{
			k1.push_back(i);
		}
	}
	k1.push_back(n);
	for(int i=0;i<m;i++)
	{
		if(version2[i]=='.')
		{
			k2.push_back(i);
		}
	}
	k2.push_back(m);
	int i=0;
	int prev1 =0;
	int prev2 =0;
	while(i<k1.size()&&i<k2.size())
	{
		int data1= stoi(version1.substr(prev1,k1[i]-prev1));
		int data2= stoi(version2.substr(prev2,k2[i]-prev2));
		if(data1>data2)
		{
			return 1;
		}
		if(data2>data1)
		{
			return -1;
		}
		prev1=k1[i]+1;
		prev2=k2[i]+1;
		i++;
	}
	if(k1.size()==k2.size())return 0;
	if(k1.size()>k2.size())
	{
		while(i<k1.size())
		{
			int data1= stoi(version1.substr(prev1,k1[i]-prev1));
			if(data1>0)return 1;
			prev1=k1[i]+1;
			i++;
		}
	}
	if(k1.size()<k2.size())
	{
		while(i<k2.size())
		{
			int data1= stoi(version2.substr(prev2,k2[i]-prev2));
			if(data1>0)return -1;
			prev2=k2[i]+1;
			i++;
		}
	}
	return 0;
    }
};