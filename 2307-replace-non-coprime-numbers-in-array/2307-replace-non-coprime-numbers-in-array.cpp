class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
	stack<int> st;
	for(int i:nums)
	{
		int x = i;
		while(!st.empty())
		{
			int a = st.top();
			int b = x;
			while(b!=0)
			{
				int temp=b;
				b=a%b;
				a=temp;
			}
			if(a>1)
			{
				int k = (x/a)*st.top();
				st.pop();
				x=k;
			}
			else
			{
				break;
			}
		}
		st.push(x);
	}
	int n = st.size();
	vector<int> ans(n);
	if(n==0)return ans;
	for(int i=n-1;i>=0;i--)
	{
		ans[i]=st.top();
		st.pop();
	}
	return ans;
    }
};