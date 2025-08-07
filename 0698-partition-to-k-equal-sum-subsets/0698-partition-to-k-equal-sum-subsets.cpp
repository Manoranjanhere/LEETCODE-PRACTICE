class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)return false;
        int target = sum/k;
        vector<int> bucket(k,0);
        return solve(nums,bucket,0,target);
    }
    bool solve(vector<int>& nums,vector<int>& bucket, int ind,int target)
    {
        if(ind == nums.size())
        {
            for(int i=0;i<bucket.size();i++)
            {
                if(bucket[i]!=target)
                {
                    return false;
                }
            }
                return true;
        }
        
        for(int i=0;i<bucket.size();i++)
        {
            if(bucket[i]+nums[ind]>target)continue;
            bucket[i]+=nums[ind];
            if(solve(nums,bucket,ind+1,target))return true;
            bucket[i]-=nums[ind];
            if(bucket[i]==0)break;
        }
        return false;
    }
};