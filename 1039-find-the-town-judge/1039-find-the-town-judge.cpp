class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> store(n+1,0);
        for(auto i:trust)
        {
            store[i[0]]--;
            store[i[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(store[i]==n-1)return i;
        }
        return -1;
    }
};