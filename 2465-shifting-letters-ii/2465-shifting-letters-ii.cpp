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
        for(int i=1;i<n;i++)
        {
            work[i]+=work[i-1];
        }
        for(int i=0;i<n;i++)
        {
            int shift = work[i]%26;
            int new_char = ((s[i] - 'a' + shift) % 26 + 26) % 26 + 'a';
ans += static_cast<char>(new_char);

        }
        return ans;
    }
};