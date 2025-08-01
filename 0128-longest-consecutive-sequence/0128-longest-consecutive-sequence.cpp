class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if(nums.size()==0)return 0;
        for(int i:nums)
        {
            st.insert(i);
        }
        int ans=1;
        for(int i:st)
        {
            if(st.find(i-1)==st.end())
            {
                int c=1;
                int num =i;
                while(st.find(num+1)!=st.end())
                {
                    c++;
                    num++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};