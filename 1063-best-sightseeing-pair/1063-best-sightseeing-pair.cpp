class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> prefsum;
        prefsum.push_back(values[0]);
        int ans=0;
        int n = values.size();
        for(int i=1;i<n;i++)
        {
            if(prefsum[i-1]<values[i]+i)
            {
                prefsum.push_back(values[i]+i);
            }
            else
            {
                prefsum.push_back(values[i-1]+i-1);
            }
        }
        for(int i=1;i<n;i++)
        {
            ans=max(ans,prefsum[i-1]+values[i]-i);
        }
        return ans;
    }
};