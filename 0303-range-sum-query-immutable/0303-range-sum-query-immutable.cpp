class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int>& nums) 
    {
        int n = nums.size();
        ans.push_back(0);
        for(int i=0;i<n;i++)
        {
            ans.push_back(ans[i]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) 
    {
        return ans[right+1]-ans[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */