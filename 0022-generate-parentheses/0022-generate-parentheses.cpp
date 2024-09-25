class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string a="";
        solve(0,0,ans,a,n);
        return ans;
    }
    void solve(int l,int r,vector<string>& ans,string a,int n)
    {
        if(l==r&&l+r==2*n)
        {
            ans.push_back(a);
            return;
        }
        if(l<n)
        {
            solve(l+1,r,ans,a+"(",n);
        }
        if(r<l)
        {
            solve(l,r+1,ans,a+")",n);
        }
    }
};