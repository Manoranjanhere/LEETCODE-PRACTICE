class Solution {
public:
    int trap(vector<int>& height) {
    int len = height.size();
    int left[len];
    int right[len];
    int trap=0;
    left[0]=height[0];
    right[len-1]=height[len-1];
   for(int i=1;i<len;i++)
   {
    left[i]= max(height[i],left[i-1]);
    right[len-i-1]= max(height[len-i-1],right[len-i]);
   }
   for(int i=0;i<len;i++)
   {
    trap+=(min(right[i],left[i])-height[i]);
   }
   return trap;
}
};