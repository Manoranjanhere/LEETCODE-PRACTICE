class Solution {
public:
    bool canChange(string start, string target) 
    {
        int n = start.length();
        int m = target.length();
        if(m!=n)return false;
        int stl=0;
        int str=0;
        vector<int> a1;
        vector<int> a2;
        int c=0;
        int mstl=m;
        int mstl1=m;
        int mstr=m;
        int mstr1=m;
        for(int i=0;i<n;i++)
        {
            while(i<n&&(start[i]=='L'||start[i]=='_'))
            {
                if(start[i]=='L')
                {
                    c++;
                }
                i++;
            }
            a1.push_back(c);
            if(i==n)break;
            c=0;
            while(i<n&&(start[i]=='R'||start[i]=='_'))
            {
                if(start[i]=='R')
                {
                    c++;
                }
                i++;
            }
            a1.push_back(c);
            int c=0;
            if(i==n-1&&start[i]=='L')
            {
                a1.push_back(1);
            }
        }
        c=0;
        for(int i=0;i<n;i++)
        {
            while(i<n&&(target[i]=='L'||target[i]=='_'))
            {
                if(target[i]=='L')
                {
                    c++;
                }
                i++;
            }
            a2.push_back(c);
            if(i==n)break;
            c=0;
            while(i<n&&(target[i]=='R'||target[i]=='_'))
            {
                if(target[i]=='R')
                {
                    c++;
                }
                i++;
            }
            a2.push_back(c);
            int c=0;
            if(i==n-1&&target[i]=='L')
            {
                a2.push_back(1);
            }
        }
        c=0;
        for(int i=0;i<m;i++)
        {
            if(start[i]=='L')
            {
                stl=i;
                mstl=min(mstl,i);
            }
            if(start[i]=='R')
            {
                str=i;
                mstr=min(mstr,i);
            }
        }
        int stl1=0;
        int str1=0;
        for(int i=0;i<m;i++)
        {
            if(target[i]=='L')
            {
                stl1=i;
                mstl1=min(mstl1,i);
                
            }
            if(target[i]=='R')
            {
                str1=i;
                mstr1=min(mstr1,i);
            }
        }
        if(stl1>stl)
        {
            return false;
        }
        if(str1<str)
        {
            return false;
        }
        if(mstl1>mstl)
        {
            return false;
        }
        if(mstr1<mstr)
        {
            return false;
        }
        for(int i:a2)
        {
            cout<<i<<" ";
        }
        if(a1!=a2)return false;
        return true;
    }
};