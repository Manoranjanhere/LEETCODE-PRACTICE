class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        string ans ="";
        vector<int>work(n,0);
        for(auto i:shifts)
        {
            if(i[2]==1)
            {
                
                    
                        work[i[0]]+=1;
                        if(i[1]+1<n)
                        {
                            work[i[1]+1]+=-1;
                        }
                
            }
            else
            {
                work[i[0]]-=1;
                        if(i[1]+1<n)
                        {
                            work[i[1]+1]+=+1;
                        }
            }
        }
        work[0]%=26;
        for(int i=1;i<n;i++)
        {
            work[i]+=work[i-1];
            work[i]%=26;
            cout<<work[i]<<" ";
        }
        int i=0;
        for(char c:s)
        {
            int st =static_cast<int>(c)+work[i];
            if(st<97)
            {
                ans+=static_cast<char>(122-(96-st));
            }
            else if(st>122)
            {
                ans+=static_cast<char>((st-122)+96);
            }
            else
            {
                ans+=static_cast<char>(st);
            }
            i++;
        }
        return ans;
    }
};