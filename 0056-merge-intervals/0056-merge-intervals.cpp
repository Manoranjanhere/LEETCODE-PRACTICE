class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n= intervals.size();
        if(n==0) return {};
        for(int i=0;i<n-1;i++)
        {
            while(i<n-1&&intervals[i][1]>=intervals[i+1][0])
            {
                intervals[i][1]=max(intervals[i][1],intervals[i+1][1]);
                intervals.erase(intervals.begin()+i+1);
                --n;
            }
        }
        return intervals;
    }
};