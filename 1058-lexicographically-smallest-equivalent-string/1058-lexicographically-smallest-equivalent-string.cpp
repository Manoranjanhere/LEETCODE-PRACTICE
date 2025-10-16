class Solution {
public:
    unordered_map<char,char> parent;
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        for(char i='a';i<='z';i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            unite(s1[i],s2[i]);
        }
        string ans ="";
        for(char ch:baseStr)
        {
            ans+=find(ch);
        }
        return ans;
    }
    void unite(char u,char v)
    {
        char up = find(u);
        char vp = find(v);
        if(up>vp)
        {
            parent[up]=vp;
        }
        else
        {
            parent[vp]=up;
        }
    }
    char find(char ch)
    {
        if(parent[ch]!=ch)
        {
            parent[ch]=find(parent[ch]);
        }
        return parent[ch];
    }
};