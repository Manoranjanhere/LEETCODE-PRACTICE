class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       long long sum=0;
       long long maxx =0;
       unordered_set<int>store;
       int l=0;
       for(int i=0;i<nums.size();i++)
       {
            while(store.find(nums[i])!=store.end())
            {
                sum-=nums[l];
                store.erase(nums[l]);
                l++;
            }
            sum+=nums[i];
            store.insert(nums[i]);
            if(i-l+1==k)
            {
                maxx=max(sum,maxx);
                sum-=nums[l];
                store.erase(nums[l]);
                l++;
            }
       }
        return maxx;
    }
};
