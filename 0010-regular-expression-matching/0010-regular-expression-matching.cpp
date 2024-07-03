class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();
        
        int i = 0, k = 0;
        
        while (i < ns || k < np) {
            if (k + 1 < np && p[k + 1] == '*') {
                // If the next character in the pattern is '*'
                if (k < np && (i < ns && (s[i] == p[k] || p[k] == '.'))) {
                    // Try to match the rest of the string and pattern recursively
                    if (isMatch(s.substr(i), p.substr(k + 2))) {
                        return true;
                    }
                    i++;
                } else {
                    k += 2;
                }
            } else if (k < np && (i < ns && (s[i] == p[k] || p[k] == '.'))) {
                // If current characters match or pattern has '.', move both pointers
                i++;
                k++;
            } else {
                return false;
            }
        }
        
        // Check for remaining '*' in the pattern
        while (k + 1 < np && p[k + 1] == '*') {
            k += 2;
        }
        
        return i == ns && k == np;
    }
};
