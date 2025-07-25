class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int ans =0;
        int m=INT_MIN;
        for(int i:nums)
        {
            st.insert(i);
        }
        for(int i:st)
        {
            if(i>0)
            {
                ans+=i;
            }
            else
            {
                m=max(m,i);
            }
        }
        if(ans==0)return m;
        return ans;
    }
};