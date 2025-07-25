class TrieNode {
public:
    TrieNode* children[26];
    bool isterminal;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        isterminal = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchHelper(string& word, TrieNode* node, int index) {
        if (index == word.size())
            return node->isterminal;

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchHelper(word, node->children[i], index + 1))
                    return true;
            }
            return false;
        } else {
            int ind = ch - 'a';
            if (ind < 0 || ind >= 26) return false;  // safeguard
            if (node->children[ind] == nullptr)
                return false;
            return searchHelper(word, node->children[ind], index + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int ind = ch - 'a';
            if (node->children[ind] == nullptr)
                node->children[ind] = new TrieNode();
            node = node->children[ind];
        }
        node->isterminal = true;
    }

    bool search(string word) {
        return searchHelper(word, root, 0);
    }
};
