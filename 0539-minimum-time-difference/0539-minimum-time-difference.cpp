class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int ans=INT_MAX;
            
        for(int i=0;i<timePoints.size()-1;i++)
        {
            int hour1= stoi(timePoints[i].substr(0,2));
            int min1= stoi(timePoints[i].substr(3,2));
            int hour2= stoi(timePoints[i+1].substr(0,2));
            int min2= stoi(timePoints[i+1].substr(3,2));
        ans=min(ans,((hour2-hour1)*60+(min2-min1)));
            
        }
        int hourLast = stoi(timePoints[timePoints.size() - 1].substr(0, 2));
        int minLast = stoi(timePoints[timePoints.size() - 1].substr(3, 2));
        
        int hourFirst = stoi(timePoints[0].substr(0, 2));
        int minFirst = stoi(timePoints[0].substr(3, 2));
        
        // Wrap-around difference (from the last time to the first time of the next day)
        int wrapAroundDiff = (24 - hourLast + hourFirst) * 60 + (minFirst - minLast);
        ans = min(ans, wrapAroundDiff);
        return ans;
    }
};