class Solution {
public:
    string multiply(string num1, string num2) {
	if(num1=="0"||num2=="0")return "0";
	vector<string> store;
	int k=0;
        for(int i=num2.size()-1;i>=0;i--)
	{
		int carry=0;
		int num = num2[i]-'0';
		string ans="";
		for(int j=num1.size()-1;j>=0;j--)
		{
			int val=num1[j]-'0';
			int mul = num*val+carry;
			int add = mul%10;
			carry=mul/10;
			ans=to_string(add)+ans;
		}
		if(carry>0)
		{
			ans=to_string(carry)+ans;
		}
		ans.append(k,'0');
		k++;
		store.push_back(ans);
	}
	long long maxsize=0;
	for(int i=0;i<store.size();i++)
	{
		maxsize=max(maxsize,(long long)store[i].size());
	}
	for(int i=0;i<store.size();i++)
	{
		if(store[i].size()<maxsize)
		{
			store[i].insert(0,maxsize-store[i].size(),'0');
		}
	}
	string final="";
	int carry=0;
	for(int i=maxsize-1;i>=0;i--)
	{
		int sum =0;
		for(int j=0;j<store.size();j++)
		{
			sum+=store[j][i]-'0';
		}
		sum+=carry;
		int val = sum%10;
		carry=sum/10;
		final=to_string(val)+final;
	}
	if(carry>0)
	{
		final=to_string(carry)+final;
	}
	return final;
    }
};