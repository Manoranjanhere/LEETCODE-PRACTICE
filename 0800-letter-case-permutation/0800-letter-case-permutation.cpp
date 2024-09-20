class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s,ans,"",0);
        return ans;
    }
    void solve(string s,vector<string>& ans,string st,int ind)
    {
        if(ind==s.length()){
            ans.push_back(st);
            return;
        }
            if(ind<s.length()&&!isalpha(s[ind]))
            {
                solve(s,ans,st+s[ind],ind+1);
            }
            else
            {
            solve(s,ans,st+(char)tolower(s[ind]),ind+1);
            solve(s,ans,st+(char)toupper(s[ind]),ind+1);
            }
        }
};