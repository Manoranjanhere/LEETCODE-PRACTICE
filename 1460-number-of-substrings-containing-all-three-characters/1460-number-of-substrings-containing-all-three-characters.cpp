class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int>pos{-1,-1,-1};
       int ans =0;
       for(int i=0;i<n;i++)
       {
        pos[s[i]-'a']=i;
        ans+=1+min({pos[0],pos[1],pos[2]});
       }
       return ans;
    }
};