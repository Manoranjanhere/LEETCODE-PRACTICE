#include <vector>
#include <algorithm> // For std::find

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::vector<int> rows;
        std::vector<int> cols;
        int n = matrix.size();
        int m = matrix[0].size();
        
        // First pass: record all rows and columns that have zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) 
                {
                        rows.push_back(i);
                    
                        cols.push_back(j);
                    
                }
            }
        }
        
        // Second pass: set the rows to zero
        for (int row : rows) {
            for (int j = 0; j < m; j++) {
                matrix[row][j] = 0;
            }
        }
        
        // Third pass: set the columns to zero
        for (int col : cols) {
            for (int i = 0; i < n; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
