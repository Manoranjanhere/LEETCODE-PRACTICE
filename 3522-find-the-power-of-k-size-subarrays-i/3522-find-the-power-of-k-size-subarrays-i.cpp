class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int s=0;
        if(k==1) return nums;
        for(int i=0;i<k-1;i++)
        {
            if(nums[i]!=nums[i+1]-1)
            {
                if(ans.size()==0)
                {
                    ans.push_back(-1);
                }
                s=i;
            }
        }
        cout<<s;
        if(ans.size()==0)
        {
            ans.push_back(nums[k-1]);
        }
        for(int i=k;i<nums.size();i++)
        {
            
            if(nums[i-1]!=nums[i]-1)
            {
                s=i-1;
                ans.push_back(-1);
            }
            else if(nums[i-1]<nums[i]&&i-k>=s)
            {
                ans.push_back(nums[i]);
            }
            else
            {
                 ans.push_back(-1);
            }
            cout<<s;
        }
        return ans;
    }
};