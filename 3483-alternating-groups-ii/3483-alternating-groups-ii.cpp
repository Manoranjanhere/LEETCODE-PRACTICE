class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++)
        {
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        if(n==0)return 0;
        int c=0;
        bool st;
        if(colors[0]==1)
        {
            st=true;
        }
        else
        {
            st=false;
        }
        int latest=0;
        for(int i=1;i<k;i++)
        {
            if(colors[i]==1&&st==true)
            {
                latest=i;
            }
            else if(colors[i]==0&&st==false)
            {
                latest=i;
            }
            else if(colors[i]==0)
            {
                st=false;
            }
            else if(colors[i]==1)
            {
                st =true;
            }
        }
        if(latest==0)
        {
            c++;
        }
        for(int i=k;i<n;i++)
        {
            if(colors[i]==1&&st==true)
            {
                latest=i;
            }
            else if(colors[i]==0&&st==false)
            {
                latest=i;
            }
            else
            {
                if(colors[i]==0)
                {
                    st=false;
                }
                if(colors[i]==1)
                {
                    st =true;
                }
                if(i-k+1>=latest)
                {
                    c++;
                }
            }
        }
        return c;
    }
};