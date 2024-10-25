class Solution {
public:
  int maxProduct(vector<int>& A) {
    int aage=1;
    int peeche=1;
    int n = A.size();
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        aage *=A[i];
        peeche*=A[n-i-1];
        ans=max({ans,aage,peeche});
        if(aage==0)aage=1;
        if(peeche==0)peeche=1;
    }
    return ans;
  }
};