class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        unordered_set<int> seen;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(seen.count(A[i]))
            {
                c++;
            }
            else
            {
                seen.insert(A[i]);
            }
            if(seen.count(B[i]))
            {
                c++;
            }
            else
            {
                seen.insert(B[i]);
            }
            ans[i]=c;
        }
        return ans;
    }
};