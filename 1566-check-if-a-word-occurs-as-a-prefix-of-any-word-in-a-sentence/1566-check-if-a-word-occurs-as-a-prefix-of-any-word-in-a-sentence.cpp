class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        string s="";
        vector<string> store;
        for(char ch :sentence)
        {
            if(ch!=' ')
            {
                s+=ch;
            }
            else
            {
                store.push_back(s);
                s="";
            }
        }
        store.push_back(s);
    
    int n = searchWord.length();

    for(int i=0;i<store.size();i++)
    {
        if(store[i].length()>=n)
        {
            if(searchWord==store[i].substr(0,n))
            {
                return i+1;
            }
        }
    }
    return -1;
    }
};