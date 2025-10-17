class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<bool> vis(n,false);
        while(!q.empty())
        {
            int curr = q.front();
            if(arr[curr]==0)return true;
            vis[curr]=true;
            q.pop();
            int val = arr[curr];
            if(curr+val<n&&!vis[curr+val])
            {
                if(arr[curr+val]==0)return true;
                q.push(curr+val);
            }
            if(curr-val>=0&&!vis[curr-val])
            {
                if(arr[curr-val]==0)return true;
                q.push(curr-val);
            }
        }
        return false;
    }
};