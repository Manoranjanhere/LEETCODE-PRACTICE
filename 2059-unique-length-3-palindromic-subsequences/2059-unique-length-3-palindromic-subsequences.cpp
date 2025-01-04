class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> store;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(store.find(s[i])==store.end())
            {
                unordered_set<char>count;
                store.insert(s[i]);
                int end = s.rfind(s[i]);
                if(end>i)
                {
                    for(int j=i+1;j<end;j++)
                    {
                        count.insert(s[j]);
                    }
                }
                c+=count.size();
            }
        }
        return c;
    }
};