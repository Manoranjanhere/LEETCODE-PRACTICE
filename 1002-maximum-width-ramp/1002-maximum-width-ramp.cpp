class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        int result =0;
        for(int i=0;i<n;i++)
        {
            if(st.empty()||nums[st.top()]>nums[i])
            {
                st.push(i);
            }
        }
        for(int j=n-1;j>=0;j--)
        {
            while(!st.empty()&&nums[j]>=nums[st.top()])
            {
                result =max(result,j-st.top());
                st.pop();
            }
        }
        return result;
    }
};