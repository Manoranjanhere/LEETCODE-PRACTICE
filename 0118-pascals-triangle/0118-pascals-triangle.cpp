class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int> store;
            store.push_back(1);
            for(int j=0;j<ans[i-1].size()-1;j++)
            {
                store.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            store.push_back(1);
            ans.push_back(store);
        }
        return ans;
    }
};