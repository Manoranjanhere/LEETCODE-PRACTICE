class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
       int n = s.length();
       vector<int> ans;
       if(n==0) return ans;
       if(n==1)
       {
        ans.push_back(stoi(s));
        return ans;
       }
       for(int i=0;i<n;i++)
       {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*')
        {
            vector<int> ans1= diffWaysToCompute(s.substr(0,i));
            vector<int> ans2=diffWaysToCompute(s.substr(i+1));          
            for(int l:ans1)
            {
                for(int r:ans2)
                {
                    if(s[i]=='+') ans.push_back(l+r);
                    if(s[i]=='-') ans.push_back(l-r);
                    if(s[i]=='*') ans.push_back(l*r);
                }
                
            }
        }
       }
       if(ans.size()==0)
       {
           ans.push_back(stoi(s));
        return ans; 
       }
       return ans;
    }
};