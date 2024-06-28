class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> diff;
        int n = nums.size();
        vector<int> arr(n,false);
        backtrack(nums,ans,diff,arr);
        return ans;
    }  
    void backtrack(vector<int>& nums,vector<vector<int>>& ans,vector<int>& diff,vector<int>& arr)
    {
        if(diff.size()==nums.size())
        {
            ans.push_back(diff);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!arr[i])
            {
                diff.push_back(nums[i]);
                arr[i]=true;
                backtrack(nums,ans,diff,arr);
                arr[i]=false;
                diff.pop_back();
            }
        }
    }
    

};