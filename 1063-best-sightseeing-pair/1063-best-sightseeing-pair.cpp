class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxstore= values[0];
        int ans=0;
        int n = values.size();
        for(int i=1;i<n;i++)
        {
            ans=max(ans,maxstore+values[i]-i);
            maxstore=max(maxstore,values[i]+i);
        }
        return ans;
    }
};