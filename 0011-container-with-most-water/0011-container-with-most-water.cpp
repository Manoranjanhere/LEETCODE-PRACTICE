class Solution {
public:
    int maxArea(vector<int>& height) {
	int n = height.size();
	int j=n-1;
	int i=0;
	int mx=0;
        while(i<j)
	{
		mx=max(mx,min(height[i],height[j])*(j-i));
		if(height[i]>height[j])j--;
		else i++;
	}
	return mx;
    }
};