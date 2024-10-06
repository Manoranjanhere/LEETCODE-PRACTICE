class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // If s1 is longer, swap them so s1 is always the shorter or equal length string
        if (s1.length() > s2.length()) {
            swap(s1, s2);
        }

        // Split both strings into words
        vector<string> words1 = split(s1);
        vector<string> words2 = split(s2);

        int n1 = words1.size(), n2 = words2.size();

        // Compare from the start
        int prefix = 0;
        while (prefix < n1 && words1[prefix] == words2[prefix]) {
            prefix++;
        }

        // Compare from the end
        int suffix = 0;
        while (suffix < n1 && words1[n1 - suffix - 1] == words2[n2 - suffix - 1]) {
            suffix++;
        }

        // Check if the entire words in s1 are covered by prefix and suffix
        return prefix + suffix >= n1;
    }

private:
    // Helper function to split a string into words
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
