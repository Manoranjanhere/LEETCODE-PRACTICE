class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        // keep value + original index (fixes duplicate-value bug)
        vector<pair<int,int>> sp;
        sp.reserve(n);
        for (int i = 0; i < n; ++i) sp.emplace_back(spells[i], i);
        sort(sp.begin(), sp.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first < b.first;
        });

        sort(potions.begin(), potions.end());
        vector<int> ans_sorted(n, 0);

        int left = 0;   // pointer on sorted spells (small -> large)
        int c = 0;      // count of potions processed (strongest first)

        // traverse potions from strongest to weakest
        for (int i = m - 1; i >= 0; --i) {
            while (left < n && (long long)sp[left].first * potions[i] < success) {
                ans_sorted[left] = c;
                left++;
            }
            c++;
            if (left == n) break;
        }

        // remaining spells succeed with all processed potions
        while (left < n) {
            ans_sorted[left] = c;
            left++;
        }

        // map answers back to original order
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[sp[i].second] = ans_sorted[i];
        return ans;
    }
};
