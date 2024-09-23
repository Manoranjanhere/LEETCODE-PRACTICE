class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> store;
        int l = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        solve(nums, ans, store, l, n);
        return ans;
    }

    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& store, int l, int n) {
        ans.push_back(store);

        for (int i = l; i < n; i++) {
            if (i > l && nums[i] == nums[i - 1]) continue;
            
            store.push_back(nums[i]);
            solve(nums, ans, store, i + 1, n);

            // Backtrack (remove the current element)
            store.pop_back();
        }
    }
};
