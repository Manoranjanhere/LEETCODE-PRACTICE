class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sum=0;
        unordered_map<int,int> mp;
        int n = grid.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[grid[i][j]]==0)
                {
                    mp[grid[i][j]]++;
                    sum+=grid[i][j];
                }
                else
                {
                    ans.push_back(grid[i][j]);
                }
            }
        }
        int st = (n*n)*(n*n+1)/2;
        ans.push_back(st-sum);
        return ans;
    }
};