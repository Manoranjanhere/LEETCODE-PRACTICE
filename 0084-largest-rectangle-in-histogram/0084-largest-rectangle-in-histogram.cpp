class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>le(n,-1);
        vector<int>ri(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                le[i]=st.top();
            }
            st.push(i);   
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ri[i]=st.top();
            }
            st.push(i);   
        }
        
        int area =0 ;
        for(int i=0;i<n;i++){
            area = max(area,heights[i]*(ri[i]-le[i]-1));
        }
        return area;

        // for(int i=0;i<n;i++)
        // {
        //     int sum=heights[i];
        //     int j=i+1;
        //     while(j<n&&heights[i]<=heights[j])
        //     {
        //         sum+=heights[i];
        //         j++;
        //     }
        //     j=i-1;
        //     while(j>=0&&heights[i]<=heights[j])
        //     {
        //         sum+=heights[i];
        //         j--;
        //     }
        //     if(sum>ma)
        //     {
        //         ma=sum;
        //     }
        // }
        // return ma;
    }
};