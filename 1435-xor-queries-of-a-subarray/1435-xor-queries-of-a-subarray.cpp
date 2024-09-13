class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int> pref;
        int n = arr.size();
        int op=0;
        for(int i=0;i<n;i++)
        {
            op^=arr[i];
            pref.push_back(op);
        }
        for(auto i:queries)
        {
            if(i[0]>0)
            {
                ans.push_back(pref[i[1]]^pref[i[0]-1]);
            }
            else
            {
                ans.push_back(pref[i[1]]);
            }
        }
        return ans;
    }
};