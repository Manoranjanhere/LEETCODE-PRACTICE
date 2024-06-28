class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums,ans,0);
        return ans;
    }  
    void backtrack(vector<int>& nums,vector<vector<int>>& ans,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            backtrack(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    

};