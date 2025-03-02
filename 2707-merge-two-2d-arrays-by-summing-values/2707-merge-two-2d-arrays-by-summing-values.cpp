class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1=0,n2=0;
        vector<vector<int>> ans;
        int i=0;
        while(n1<nums1.size()&&n2<nums2.size())
        {
            if(nums1[n1][0]==nums2[n2][0])
            {
                int sum=nums1[n1][1]+nums2[n2][1];
                ans.push_back({nums1[n1][0],sum});
                i++;
                n1++;
                n2++;
            }
            else if(nums1[n1][0]>nums2[n2][0])
            {
                ans.push_back(nums2[n2]);
                n2++;
                i++;
            }
            else if(nums1[n1][0]<nums2[n2][0])
            {
                ans.push_back(nums1[n1]);
                n1++;
                i++;
            }
        }
        while(n1<nums1.size())
        {
            ans.push_back(nums1[n1]);
                n1++;
                i++;
        }
        while(n2<nums2.size())
        {
            ans.push_back(nums2[n2]);
                n2++;
                i++;
        }
        return ans;
    }
};