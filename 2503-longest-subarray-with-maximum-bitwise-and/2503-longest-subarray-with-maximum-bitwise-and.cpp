class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int c=0;
        int st=0;
        int max= *max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==max)
            {
                c++;
                if(c>st)
                {
                    st=c;
                }
            }
            else
            {
                c=0;
            }
        }
        return st;
    }
};