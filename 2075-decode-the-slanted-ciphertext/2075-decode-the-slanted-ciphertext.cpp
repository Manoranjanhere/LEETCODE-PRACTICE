class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 0) return "";
        
        int n = encodedText.size();
        int cols = n / rows;
        
        vector<vector<char>> mat(rows, vector<char>(cols));
        
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }
        
        string ans = "";
        
        for (int j = 0; j < cols; j++) {
            int i = 0, k = j;
            while (i < rows && k < cols) {
                ans += mat[i][k];
                i++;
                k++;
            }
        }
        
        // remove trailing spaces
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};