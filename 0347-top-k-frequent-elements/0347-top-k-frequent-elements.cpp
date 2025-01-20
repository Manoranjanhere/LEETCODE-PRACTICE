class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        vector<int> ans;
        while(!pq.empty()&&k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};