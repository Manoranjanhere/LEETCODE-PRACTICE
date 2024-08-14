class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> mp;
       for(int i=0;i<nums.size();i++)
       {
        int req = target-nums[i];
        if(mp.find(req)!=mp.end())
        {
            return {mp[req],i};
        }
        mp[nums[i]]=i;
       }
       return {};
    }
};