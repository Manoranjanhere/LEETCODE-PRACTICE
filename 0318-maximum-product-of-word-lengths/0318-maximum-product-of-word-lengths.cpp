class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<unordered_map<char,int>> st(n);
        for(int i=0;i<n;i++)
        {
            for(char c:words[i])
            {
                st[i][c]++;
            }
        }
        int ans =0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool found = false;
                for(char c:words[i])
                {
                    if(st[j][c]>=1)
                    {
                        found=true;
                        break;
                    }
                }
                if(!found)
                {
                    int m =words[i].size()*words[j].size();
                    ans=max(ans,m);
                }
            }
        }
        return ans;
    }
};