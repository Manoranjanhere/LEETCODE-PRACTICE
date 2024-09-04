class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l[n];
        int r[n];
        l[0]=height[0];
        r[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            l[i]=max(height[i],l[i-1]);
            r[n-i-1]=max(height[n-i-1],r[n-i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(min(l[i],r[i])-height[i]);
        }
        return sum;
    }
};