class Solution {
public:
    string smallestNumber(string pattern) {
        string ans ="";
        for(int i=1;i<=pattern.size()+1;i++)
        {
            ans+=(i+'0');
        }
        while(!check(ans,pattern))
        {
            next_permutation(ans.begin(),ans.end());
        }
        return ans;
    }
    bool check(string ans,string pattern)
    {
        for(int i=0;i<pattern.size();i++)
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