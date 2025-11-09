class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
            {
                mp[nums[i]].push_back(i);
            }
        for(auto j:mp)
            {
                if(j.second.size()>=3)
                {
                    for(int i=0;i<j.second.size()-2;i++)
                        {
                            ans=min(ans,2*(j.second[i+2]-j.second[i]));
                        }
                }
            }
        return (ans==INT_MAX)?-1:ans;
    }
};