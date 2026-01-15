class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(char ch:ransomNote)mp1[ch]++;
        for(char ch:magazine)mp2[ch]++;
        for(auto i:mp1)
        {
            if(i.second>mp2[i.first])return false;
        }
        return true;
    }
};