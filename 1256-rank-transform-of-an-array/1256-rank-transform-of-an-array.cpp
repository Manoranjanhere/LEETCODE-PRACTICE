class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        if(n==0) return ans;
        int c=1;
        map<int,int>mp;
        vector<int> st =arr;
        sort(arr.begin(),arr.end()); 
        mp[arr[0]]=c;
        for(int i=1;i<n;i++)
        {
            if(arr[i]!=arr[i-1])
            {
                c++;
                mp[arr[i]]=c;
            }
            mp[arr[i]]=c;
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(mp[st[i]]);
        }
        return ans;
    }
};