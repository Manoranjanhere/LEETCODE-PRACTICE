class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans ="";
        for(int i=1;i<=n+1;i++)
        {
            ans+=(i+'0');
        }
        while(!check(ans,pattern,n))
        {
            next_permutation(ans.begin(),ans.end());
        }
        return ans;
    }
    bool check(string ans,string pattern,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(pattern[i]=='I')
            {
                if(ans[i+1]<ans[i])
                {
                    return false;
                }
            }
            else
            {
                if(ans[i+1]>ans[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};