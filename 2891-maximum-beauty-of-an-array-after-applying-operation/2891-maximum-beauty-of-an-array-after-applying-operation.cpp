class Solution {
public:
    static int maximumBeauty(vector<int>& nums, int k) {
        int n = *max_element(nums.begin(),nums.end());
        vector<int> st(n+k+2,0);
        for(int i:nums)
        {
            if(i-k>0)
            {
                st[i-k]+=1;
            }
            else
            {
                st[0]+=1;
            }
            st[i+k+1]-=1;
        }
        int mx=0;
        for(int i=1;i<n+k+1;i++)
        {
            st[i]+=st[i-1];
            mx=max(mx,st[i]);
        }
        return mx;
    }
};