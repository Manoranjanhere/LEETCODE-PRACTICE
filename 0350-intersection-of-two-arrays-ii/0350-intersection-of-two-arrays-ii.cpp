class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2= nums2.size();
        vector<bool>check1(n1,false);
        vector<bool>check2(n2,false);
        vector<int> ans;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(nums1[i]==nums2[j]&&!check1[i]&&!check2[j])
                {
                    ans.push_back(nums1[i]);
                    check1[i]=true;
                    check2[j]=true;
                }
            }
        }
    return ans;

    }
};