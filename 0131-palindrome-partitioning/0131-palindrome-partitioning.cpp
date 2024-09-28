class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        // vector<string> prefix;
        // vector<string> suffix;
        // string a ="";
        // for(int i=0;i<n;i++)
        // {
        //     a+=s[i];
        //     if(pallindrome(a))
        //     {
        //         prefix.push_back(a);
        //     }
            
        // }   
            vector<vector<string>> ans;
            vector<string> run;
            solve(s,ans,run,0);
            return ans;
    }
    void solve(string s,vector<vector<string>>& ans,vector<string>& run,int l)
    {
        if(l==s.size())
        {
                ans.push_back(run);
                return;
        }
        for(int i=l;i<s.size();i++)
        {
            string substr = s.substr(l, i - l + 1);
            if(pallindrome(substr))
            {
                run.push_back(substr);
                solve(s,ans,run,i+1);
                run.pop_back();
            }
        }
    }
    bool pallindrome(string a)
    {
        return (a==string(a.rbegin(),a.rend()));
       
    }
};