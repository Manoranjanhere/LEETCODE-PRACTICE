class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
       int ans =0;
       int left=0;
       for(int i=0;i<n;i++)
       {
        mp[s[i]]++;
        while(mp['a']>=1&&mp['b']>=1&&mp['c']>=1)
        {
            ans+=(n-i);
            mp[s[left]]--;
            left++;
        }
       }
       return ans;
    }
};