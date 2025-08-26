class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        unordered_map<int,int> mp;
        for (int x : nums) mp[x]++;

        vector<int> st;
        st.reserve(mp.size());
        for (auto &p : mp) st.push_back(p.first);
        sort(st.begin(), st.end());

        // Note: don't early-return on ns<k; it's not a valid condition.
        int ns = (int)st.size();

        // Greedily consume counts starting from the smallest available key.
        for (int i = 0; i < ns; ++i) {
            int start = st[i];
            int cnt = mp[start];
            if (cnt == 0) continue;                // already fully used

            // Need cnt copies of a run [start, start+1, ..., start+k-1]
            for (int d = 0; d < k; ++d) {
                int val = start + d;
                if (mp[val] < cnt) return false;   // missing needed numbers
                mp[val] -= cnt;
            }
        }
        return true;
    }
};
