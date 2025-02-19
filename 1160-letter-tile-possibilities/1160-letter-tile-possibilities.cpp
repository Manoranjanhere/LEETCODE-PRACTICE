class Solution {
public:
    int numTilePossibilities(string tiles) 
    {
            int c[26]={0};
            for(char ch:tiles)
            {
                c[ch-'A']++;
            }
            return find(c);
            
       }
       int find(int c[26])
       {
        int t=0;
        for(int pos=0;pos<26;pos++)
        {
            if(c[pos]==0)
            {
                continue;
            }
            t++;
            c[pos]--;
            t+=find(c);
            c[pos]++;
        }
        return t;
       }
};