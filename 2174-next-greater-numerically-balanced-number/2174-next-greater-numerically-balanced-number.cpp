class Solution {
public:
    bool isBeautiful(int num) {
        string s = to_string(num);
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        for (auto [ch, cnt] : count)
            if (cnt != ch - '0') return false;
        return true;
    }

    int nextBeautifulNumber(int n) {
        if(n>=666666)return 1224444;
        for (int i = n + 1; ; ++i) {
            if (isBeautiful(i)) return i;
        }
        return -1; // unreachable
    }
};
