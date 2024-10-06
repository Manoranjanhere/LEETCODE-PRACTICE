class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1.length() > s2.length()) {
            swap(s1, s2);
        }
        vector<string> word1= split(s1);
        vector<string> word2= split(s2);
         int n1 = word1.size();
         int n2 = word2.size();
         int p=0;
         while(p<n1&&word1[p]==word2[p])
         {
            p++;
         }
         int suffix = 0;
        while (suffix < n1 && word1[n1 - suffix - 1] == word2[n2 - suffix - 1]) {
            suffix++;
        }
                return p + suffix >= n1;
    }
    vector<string> split(const string& s) {
    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}
};