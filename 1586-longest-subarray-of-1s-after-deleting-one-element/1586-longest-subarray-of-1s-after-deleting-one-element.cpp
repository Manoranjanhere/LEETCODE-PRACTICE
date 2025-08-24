class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans =0;
        int ind=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            while(mp[0]>1)
            {
                mp[nums[ind]]--;
                ind++;
            }
            ans=max(ans,i-ind);
        }
        return ans;
    }
};