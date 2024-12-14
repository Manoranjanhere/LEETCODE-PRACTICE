class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        int l=0;
        int r=0;
        long long count =0;
        while(r<n)
        {
            mp[nums[r]]++;
            while(mp.rbegin()->first-mp.begin()->first>2)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
};