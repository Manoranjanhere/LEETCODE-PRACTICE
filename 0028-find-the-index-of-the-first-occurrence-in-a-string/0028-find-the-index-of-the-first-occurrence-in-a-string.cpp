class Solution {
public:
    int strStr(string haystack, string needle) {
        int haysize= haystack.size();
	int ns= needle.size();
	for(int i=0;i<=haysize-ns;i++)
	{
		if(haystack[i]==needle[0])
		{
			if(needle==haystack.substr(i,ns))return i;
		}
		
	}
	return -1;
    }
};