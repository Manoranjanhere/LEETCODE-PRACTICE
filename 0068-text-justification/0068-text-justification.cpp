class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length(); // 1 for space
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Last line or single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += ' ';
                }
                line.append(maxWidth - line.length(), ' ');
            } else {
                int totalSpaces = maxWidth;
                for (int k = i; k < j; k++) totalSpaces -= words[k].length();
                int space = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line.append(space, ' ');
                    if (extra-- > 0) line += ' ';
                }
                line += words[j - 1];
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
