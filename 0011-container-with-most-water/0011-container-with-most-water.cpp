class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left =0;
        int right = n-1;
        int ans = 0;
        while(left<right)
        {
            ans = max(ans,min(heights[right],heights[left])*(right-left));
            if(heights[left]>heights[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return ans;
    }
};