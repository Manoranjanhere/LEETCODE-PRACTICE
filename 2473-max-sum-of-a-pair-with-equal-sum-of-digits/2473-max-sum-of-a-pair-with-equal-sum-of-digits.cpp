class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> store;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            int store = nums[i];
            while(nums[i]>0)
            {
                int rem=nums[i]%10;
                sum+=rem;
                nums[i]/=10;
            }
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,mp[sum]+store);
                mp[sum]=max(mp[sum],store);
            }
            else
            {
                mp[sum]=store;
            }
        }
        return ans;
    }
};