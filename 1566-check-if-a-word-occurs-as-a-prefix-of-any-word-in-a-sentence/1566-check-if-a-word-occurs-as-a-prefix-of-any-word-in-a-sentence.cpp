class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        string s="";
        vector<string> store;
        int n = searchWord.length();
        int i=1;
        for(char ch :sentence)
        {
            if(ch!=' ')
            {
                s+=ch;
            }
            else
            {
                if(s.length()>=n)
                {
                    if(searchWord==s.substr(0,n))
                    {
                        return i;
                    }
                }
                i++;
                s="";
            }
        }
        if(s.length()>=n)
                {
                    if(searchWord==s.substr(0,n))
                    {
                        return i;
                    }
                }
                return -1;
    }
};