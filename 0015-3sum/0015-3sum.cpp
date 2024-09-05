class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n= nums.size();
       set<vector<int>> st;
       sort(nums.begin(), nums.end());
       

      for(int i=0; i<n; i++){
        int j=i+1;
        int k=nums.size()-1;
        vector<int> temp;
        

        while(j<k){
            int sum= nums[i]+nums[j]+nums[k];
            
            if(sum==0){
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                st.insert(temp);
                temp.clear();
                j++;
                k--;
            }
            else if(sum<0){
                j++;
               }
            else{
                k--;
            }
           }
          }
      vector<vector<int>> ans(st.begin(), st.end());
     
      return ans;
    }
};