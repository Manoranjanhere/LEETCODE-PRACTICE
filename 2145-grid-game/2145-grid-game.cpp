class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n = grid[0].size();
        long long store=0;
        for(int i=0;i<n-1;i++)
        {
            store+=grid[1][i];
        }
        long long ans=LLONG_MAX;
        long long store2=0;
        for(int i=n-2;i>=0;i--)
        {
            ans=min(ans,max(store,store2));
            store-=grid[1][i];
            store2+=grid[0][i+1];
        }
        ans=min(ans,max(store,store2));
        return ans;

    }
};