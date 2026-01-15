class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> st=strs;
        for(string &i:st)
        {
            sort(i.begin(),i.end());
        }
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++)
        {
            mp[st[i]].push_back({i});
        }
        vector<vector<string>> ans;
        for(auto i:mp)
        {
            vector<string> one;
            for(int i:i.second)one.push_back(strs[i]);
            ans.push_back(one);
        }
        return ans;
    }
};