class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxele=0,maxc=0;

        for(int n:nums)
        {
            int c =++mp[n];
            if(c>maxc)
            {
                maxele=n;
                maxc=c;
            }
        }
        return maxele;
        
    }
};