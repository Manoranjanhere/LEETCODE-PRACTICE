class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums)
        {
            mp[num]++;
        }
        int c=0;
        for(auto i:mp)
        {
            c+=i.second/2;
        }
        if(c==nums.size()/2)
        {
            return true;
        }
        return false;
    }
};