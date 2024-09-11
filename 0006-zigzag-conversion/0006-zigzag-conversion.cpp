class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string ans="";
        int w=0;
        string arr[numRows];
        while(w!=n)
        {
            for(int i=0;i<numRows;i++)
            {
                if(w<n)
                {
                    arr[i]+=s[w];
                    w++;
                }
                else
                {
                    break;
                }
            }
            for(int i=numRows-2;i>0;i--)
            {
                if(w<n)
                {
                    arr[i]+=s[w];
                    w++;
                }
                else
                {
                    break;
                }
            }
            
        }
        for(int i=0;i<numRows;i++)
        {
            ans+=arr[i];
        }
        return ans;
    }
};