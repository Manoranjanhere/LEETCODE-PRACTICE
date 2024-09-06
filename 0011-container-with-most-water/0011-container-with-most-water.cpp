class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size()-1;
        int l=0;
        int max=0;
        while(l<n)
        {
            int a = min(height[l],height[n]);
            if(a*(n-l)>max)
            {
                max=a*(n-l);
            }
            if(height[l]>height[n])
            {
                n--;
            }
            else
            {
                l++;
            }

        }
        return max;
    }
};