class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int>& nums) 
    {
        int n = nums.size();
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            ans.push_back(ans[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) 
    {
        if(left!=0)
        {
        return ans[right]-ans[left-1];
        }
        else
        {
            return ans[right];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */