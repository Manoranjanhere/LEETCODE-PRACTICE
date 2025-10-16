class Solution {
public:
    unordered_map<char,char> parent;
    bool equationsPossible(vector<string>& equations) {
        for(char i='a';i<'z';i++)
        {
            parent[i]=i;
        }
        for(string i:equations)
        {
            if(i[1]=='=')
            {
                unite(i[0],i[3]);
            }
        }
        for(string i:equations)
        {
            if(i[1]=='!')
            {
                if(find(i[0])==find(i[3]))return false;
            }
        }
        return true;
    }
    void unite(char u,char v)
    {
        char up=find(u);
        char vp=find(v);
        parent[up]=vp;
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