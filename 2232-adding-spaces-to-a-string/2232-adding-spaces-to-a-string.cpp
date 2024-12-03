class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        string ans="";
        ans+=s.substr(0,spaces[0])+" ";
        for(int i=0;i<n-1;i++)
        {
            cout<<spaces[i+1]<<" ";
            ans+=s.substr(spaces[i],spaces[i+1]-spaces[i])+" ";
        }
        ans+=s.substr(spaces[n-1]);
        return ans;
    }
};