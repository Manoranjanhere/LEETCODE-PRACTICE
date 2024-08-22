class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        int count=0;
      vector<vector<int>> mp(26);
      for(int i=0;i<26;i++)
      {
        mp[i].push_back(-1);
      }
      for(int i=0;i<s.length();i++)
      {
        mp[s[i]-'A'].push_back(i);
      }
      for(int i=0;i<26;i++)
      {
        mp[i].push_back(n);
      }
      for(int i=0;i<26;i++)
      {
        for(int j=1;j<mp[i].size()-1;j++)
        {
            count+=(mp[i][j]-mp[i][j-1])*(mp[i][j+1]-mp[i][j]);
        }
      }
      return count;
    }
};