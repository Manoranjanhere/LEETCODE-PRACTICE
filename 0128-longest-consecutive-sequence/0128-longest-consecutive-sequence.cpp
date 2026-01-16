class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx=0;
        unordered_set<int> st;
        for(int i:nums)
        {
            st.insert(i);
        }
        for(int i:st)
        {
            if(!st.count(i-1))
            {
                int curr=i;
                int k=1;
                while(st.count(curr+1))
                {
                    k++;curr++;
                }
                mx=max(mx,k);
            }
        }
        return mx;
    }
};