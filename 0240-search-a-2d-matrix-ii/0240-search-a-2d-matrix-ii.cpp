class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowl=0;
        int coll=0;
        int rowr=matrix.size()-1;
        int colr=matrix[0].size()-1;
        while(rowl<=rowr&&colr>=0)
        {
            if(matrix[rowl][colr]==target)
            {
                return true;
            }
            else if(matrix[rowl][colr]>target)
            {
                colr--;
            }
            else
            {
                rowl++;
            }
        }
        return false;
    }
};