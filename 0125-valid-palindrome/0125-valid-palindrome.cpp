class Solution {
public:
    bool isPalindrome(string s) {
        string st="";
        for(char ch:s)
	{
		if(isdigit(ch)||isalpha(ch))st+=tolower(ch);
	}
	string rev=st;
	reverse(rev.begin(),rev.end());
	return (rev==st)?true:false;
    }
};