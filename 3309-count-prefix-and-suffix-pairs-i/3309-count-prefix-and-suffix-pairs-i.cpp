class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(words[i].length()<words[j].length())
                {
                    string st1 = words[j].substr(0,words[i].length());
                    string st2 = words[j].substr(words[j].length()-words[i].length());
                    if(words[i]==st1&&words[i]==st2)
                    {
                        c++;
                    }
                }
                if(words[i]==words[j])
                {
                    c++;
                }
            }
        }
        return c;
    }
};