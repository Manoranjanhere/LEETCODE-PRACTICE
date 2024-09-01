class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()-1;
        int lc= matrix[0].size()-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(matrix[mid][lc]==target)
            {
                return true;
            }
            if(matrix[mid][lc]>target)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        int row = l;
        l=0;
        while(l<=lc)
        {
            int mid=(l+lc)/2;
            if(matrix[row][mid]==target)
            {
                return true;
            }
            if(matrix[row][mid]>=target)
            {
                lc=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return false;
    }
};