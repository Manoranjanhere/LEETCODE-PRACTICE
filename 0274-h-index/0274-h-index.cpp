class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
	int c=0;
	for(int i=0;i<citations.size();i++)
	{
		if(citations[i]>i)c++;
		else break;
	}
	return c;
    }
};