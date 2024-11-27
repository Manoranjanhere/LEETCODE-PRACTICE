class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> d(n-1);
        for(int i=0;i<n-1;i++)
        {
            d[i]=i+1;
        }
        vector<int> res;
        int curr= n-1;
        for(auto query:queries)
        {
            int start = query[0];
            int end= query[1];
            while(d[start]<end)
            {
                int temp= d[start];
                d[start]=end;
                start=temp;
                --curr;
            }
            res.push_back(curr);
        }
        return res;
    }
};