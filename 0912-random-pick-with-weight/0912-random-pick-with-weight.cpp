class Solution {
public:
    vector<int> pref;
	int sum =0;
    Solution(vector<int>& w) {
        int n = w.size();
	pref.resize(n);
	pref[0]=w[0];
	for(int i=1;i<n;i++)
	{
		pref[i]=pref[i-1]+w[i];
	}
	sum= pref[n-1];
    }
    
    int pickIndex() {
        int ran= rand()%sum+1;
	int l=0;
	int r = pref.size()-1;
	while(l<=r)
	{
		int mid = l+(r-l)/2;
		if(pref[mid]==ran)return mid;
		else if(pref[mid]<ran)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
    return l;
    }
};
