class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int sz =0;
        string f="";
        for(int i=0;i<n;i++)
        {
            solve(s,i,i,sz,f);
            solve(s,i,i+1,sz,f);
        }
        return f;
    }
    void solve(string s,int left,int right,int& sz,string &f)
    {
        if(left<0||right>=s.size()||s[left]!=s[right])
        {
            return;
        }
        if(right-left+1>sz)
        {
            sz=right-left+1;
            f=s.substr(left,right-left+1);
        }
        solve(s,left-1,right+1,sz,f);
    }
};