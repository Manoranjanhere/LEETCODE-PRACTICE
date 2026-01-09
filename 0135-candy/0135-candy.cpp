class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
	vector<int> st(n,1);
	for(int i=1;i<n;i++)
	{
		if(ratings[i]>ratings[i-1]&&st[i]<=st[i-1]){int diff=st[i-1]+1-st[i];
            st[i]+=diff;
};
	}
	for(int i=n-2;i>=0;i--)
	{
		if(ratings[i]>ratings[i+1]&&st[i]<=st[i+1])
        {
	    int diff=st[i+1]+1-st[i];
            st[i]+=diff;
        }
	}
	int ans =0;
	for(int i:st)
	{
		ans+=i;
	}
	return ans;
    }
};