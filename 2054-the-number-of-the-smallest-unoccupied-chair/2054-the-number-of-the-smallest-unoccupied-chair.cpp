class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>> arrivals;
        int n = times.size();
        for(int i=0;i<n;i++)
        {
            arrivals.push_back({times[i][0],i});
        }
        sort(arrivals.begin(),arrivals.end());
        priority_queue<int,vector<int>,greater<int>>av;
        for(int i=0;i<n;i++)
        {
            av.push(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>lv;
        for(auto & arrival:arrivals)
        {
            int avt =arrival.first;
            int fn=arrival.second;
            while(!lv.empty()&&lv.top().first<=avt)
            {
                av.push(lv.top().second);
                lv.pop();
            }
            int chair =av.top();
            av.pop();

            if(fn==targetFriend)
            {
                return chair;
            }
            lv.push({times[fn][1],chair});
        }
        return -1;
    }
};