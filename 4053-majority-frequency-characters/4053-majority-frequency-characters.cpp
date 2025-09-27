class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<int,int> mp;
        for(char c:s)
        {
            mp[c]++;
        }
        unordered_map<int,vector<int>> st;
        for(auto i:mp)
        {
            st[i.second].push_back(i.first);
        }
        string ans ="";
        int tora = 0;
        int m =0;
        for(auto i:st)
        {
            if(st[i.first].size()>m)
            {
                m=st[i.first].size();
                tora = i.first;
            }
            if(st[i.first].size()==m&&i.first>tora)
            {
                tora = i.first;
            }
        }
        for(char c:st[tora])
        {
            ans+=c;
        }
        return ans;
    }
};