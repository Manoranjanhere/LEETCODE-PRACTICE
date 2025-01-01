class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.length();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int c=0,j=0;
        right.push_back(0);
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                c++;
            }
            left[i]=c;
        }
        for(int i=n-1;i>0;i--)
        {
            if(s[i]=='1')
            {
                j++;
            }
            right[i]=j;
        }
        cout<<right[1];
        int m=0;
        for(int i=0;i<n-1;i++)
        {
            m=max(m,right[i+1]+left[i]);
            cout<<right[i];
        }
        return m;
    }
};