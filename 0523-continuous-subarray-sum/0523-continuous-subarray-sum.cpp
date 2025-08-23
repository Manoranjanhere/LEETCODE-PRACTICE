class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0)return false;
        nums[0]%=k;
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
            nums[i]%=k;
        }
        unordered_map<int,int>mp;
        mp.insert({nums[0],0});
        for(int i=1;i<n;i++)
        {
            if(nums[i]==0)return true;
            if(mp.count(nums[i]%k)&&mp[nums[i]%k]!=i-1)return true;
            mp.insert({nums[i],i});
        }
        return false;
    }
};