class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int maxx=0;
        for(int j=0;j<n;j++)
        {
            long long store = (long long)nums[j];
            int c=0;
            while(st.find(store)!=st.end())
            {
                if (store > sqrt(std::numeric_limits<long long>::max())) {
                    break;
                }
                c++;
                store=store * store;
            }
             maxx = max(c,maxx);
        }
        return(maxx==1)?-1:maxx;
    }
};