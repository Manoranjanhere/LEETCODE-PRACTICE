class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int odd=0,even=1,ans=0,prefix=0;
        for(int ele:arr)
        {
            prefix+=ele;
            if(prefix%2==0)
            {
                even++;
                ans+=odd;
            }
            else
            {
                odd++;
                ans+=even;
            }
            ans%=mod;
        }
        return ans;
    }
};