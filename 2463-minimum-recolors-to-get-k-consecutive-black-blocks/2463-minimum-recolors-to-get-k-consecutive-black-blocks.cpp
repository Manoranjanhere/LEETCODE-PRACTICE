class Solution {
public:
    int minimumRecolors(string block, int k) {
        int n= block.size();
        int c=0;
        for(int i=0;i<k;i++)
        {
            if(block[i]=='W')
            {
                c++;
            }
        }
        int m=c;
        int j=0;
        for(int i=k;i<n;i++)
        {
            if(block[i]=='W')
            {
                c++;
            }
            if(block[j]=='W')
            {
                c--;
            }
            j++;
            m=min(m,c);

        }
        return m;
    }
};