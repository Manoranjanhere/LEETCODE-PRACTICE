class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int j=0;
        int n = nums.size();
        k=min(n-1,k);
        for(int i=0;i<=k;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>=2)return true;
        }
        for(int i=k+1;i<n;i++)
        {
            mp[nums[i]]++;
            mp[nums[j]]--;
            j++;
            if(mp[nums[i]]>=2)return true;
        }
        return false;
    }
};