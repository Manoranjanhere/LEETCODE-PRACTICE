class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int n = citations.size();
        if(n==1&&citations[0]==0)return 0;
        if(n==1)return 1;
        sort(citations.begin(),citations.end());
         int c=0;
         for(int i=citations[n-1];i>=0;i--)
         {
            c=0;
            for(int j=n-1;j>=0;j--){
                if(citations[j]>=i){
                    c++;
                }
                if(c==i){
                    return c;
                }
            }
         }
         return 0;
    }
};