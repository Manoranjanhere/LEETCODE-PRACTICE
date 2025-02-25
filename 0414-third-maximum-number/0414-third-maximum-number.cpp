class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int,greater<int>> st;
        for(int ele:nums)
        {
            st.insert(ele);
        }
        auto it = st.begin();
        if(st.size()<3)
        
        {
            return *it;
        }
        advance(it,2);
        return *it;
    }
};