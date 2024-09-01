class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false; // Check if matrix is empty

        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0, col = cols - 1; // Start from the top-right corner

        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // Target found
            } 
            else if (matrix[row][col] > target) {
                col--; // Move left
            } 
            else {
                row++; // Move down
            }
        }
        
        return false; // Target not found
    }
};
