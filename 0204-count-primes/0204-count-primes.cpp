class Solution {
public:
    int countPrimes(int n) {
        vector<int>seive(n+1,1);
        for(int i=2;i<n;i++)
        {
            if(seive[i]==0)continue;
            int ind=2;
            while(i*ind<n)
            {
                seive[i*ind]=0;
                ind++;
            }
        }
        int ans =0;
        for(int i=2;i<n;i++)
        {
            if(seive[i]==1)ans++;
        }
        return ans;
    }
};