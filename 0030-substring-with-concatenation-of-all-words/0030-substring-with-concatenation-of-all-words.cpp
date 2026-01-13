class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int one = words[0].size();
        int total = n * one;
        vector<int> ans;

        if (s.size() < total) return ans;

        unordered_map<string,int> str;
        for (string w : words) str[w]++;

        // try all offsets
        for (int start = 0; start < one; start++) {

            unordered_map<string,int> mp;
            int j = start;

            // build first window
            for (int i = start; i + one <= start + total; i += one) {
                string get = s.substr(i, one);
                mp[get]++;
            }

            if (mp == str) ans.push_back(j);

            // slide window
            while (j + total + one <= s.size()) {

                string del = s.substr(j, one);
                mp[del]--;
                if (mp[del] == 0) mp.erase(del);

                j += one;

                string add = s.substr(j + total - one, one);
                mp[add]++;

                if (mp == str) ans.push_back(j);
            }
        }

        return ans;
    }
};
