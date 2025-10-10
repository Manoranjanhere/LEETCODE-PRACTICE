class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int i =0;
        int sum =INT_MIN;
        int n = energy.size();
        vector<int> dp(n);
        for(int i=n-1;i>=0;i--)
        {
            if(i+k<n)
            {
                dp[i]=energy[i]+dp[i+k];
            }
            else
            {
                dp[i]=energy[i];
            }
            sum=max(dp[i],sum);
        }
        return sum;
    }
};