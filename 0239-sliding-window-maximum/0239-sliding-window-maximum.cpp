class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        multiset<int>windows;
       for(int i=0;i<k;i++)
       {
        windows.insert(nums[i]);
       }
       auto it=windows.rbegin();
       ans.push_back(*it);
       int i=0;int j=k;
       while(j<n)
       {
        windows.erase(windows.find(nums[i]));
        windows.insert(nums[j]);
        ans.push_back(*windows.rbegin());
        i++;j++;
       }
       return ans;
    }
};