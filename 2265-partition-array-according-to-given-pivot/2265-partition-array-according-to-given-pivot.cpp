class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int i=0;
        int j=n-1;
        for(int k=0,l=n-1;k<n;k++,l--)
        {
            if(nums[k]<pivot)
            {
                ans[i]=nums[k];
                i++;
            }
            if(nums[l]>pivot)
            {
                ans[j]=nums[l];
                j--;
            }
        }
        while(i<=j)
        {
            ans[i]=pivot;
            i++;
        }
        return ans;
    }
};