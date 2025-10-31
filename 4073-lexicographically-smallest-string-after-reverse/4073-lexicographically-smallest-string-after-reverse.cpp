#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;

        for (int k = 1; k <= n; k++) {
            string a = s;
            reverse(a.begin(), a.begin() + k);  
            ans = min(ans, a);

            string b = s;
            reverse(b.end() - k, b.end());     
            ans = min(ans, b);
        }

        return ans;
    }
};
