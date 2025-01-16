class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        long long res1=0;
        for(int i=0;i<nums1.size();i++)
        {
            res1^=nums1[i];
        }
        long long store=0;
        if(nums2.size()%2!=0)
        {
            store^=res1;
        }
        long long res2=0;
        for(int i=0;i<nums2.size();i++)
        {
            res2^=nums2[i];
        }
        if(nums1.size()%2!=0)
        {
            store^=res2;
        }
        return store;
    }
};