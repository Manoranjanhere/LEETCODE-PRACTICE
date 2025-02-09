class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total = (n*(n-1)/2);
        int c=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            nums[i]-=c;
            c++;
            mp[nums[i]]++;
        }
        for(auto i:mp)
        {
            long long k = i.second;
            if(k>2)
            {
                total-=(k*(k-1))/2;
            }
            else if(k==2)
            {
                total-=(k*(k-1))/2;
            }
        }
        return total;
    }
};