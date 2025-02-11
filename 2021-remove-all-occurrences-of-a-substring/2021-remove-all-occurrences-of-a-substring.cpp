class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        while(s.find(part)!=string::npos)
        {
            int k = s.find(part);
            cout<<k;
            s.erase(k,n);
        }
        return s;
    }
};