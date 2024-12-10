class Solution {
public:
    int maximumLength(string s) 
    {
        int n = s.length();
        size_t maxx=0;
        string nws=s;
        int c=0;
        for(int i=0;i<n;i++)
        {
            string a="";
            for(int j=i;j<n;j++)
            {
                if(j!=0&&s[j]!=s[j-1]&&a.length()>=1)
                {
                    break;
                }
                a+=s[j];
                c=0;
                nws=s;
                while(nws.find(a)!=string::npos)
                {
                    int ind = nws.find(a);
                    nws = nws.substr(ind+1);
                    cout<<nws<<" ";
                    c++;
                    if(c==3)
                    {
                        break;
                    }
                }
                if(c==3)
                {
                    cout<<a<<" ";
                    maxx=max(maxx,a.length());
                }
                else
                {
                    break;
                }
            }
        }
        return (maxx==0)?-1:maxx;
    }
};