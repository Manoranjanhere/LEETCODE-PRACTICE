class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        int ind =0;
        vector<vector<string>> ans;
        vector<string> store;
        solve(s,ans,store,0,n);
        return ans;
    }
    void solve(string s,vector<vector<string>>& ans,vector<string>& store,int ind,int n)
    {
        if(ind==n)
        {
            ans.push_back(store);
        }
        for(int i=ind;i<n;i++)
        {
            if(ispalindrome(s,ind,i))
            {
                store.push_back(s.substr(ind,i-ind+1));
                solve(s,ans,store,i+1,n);
                store.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int ind,int i)
    {
        while(ind<=i)
        {
            if(s[ind++]!=s[i--])
            {
                return false;
            }
        }
        return true;
    }
};