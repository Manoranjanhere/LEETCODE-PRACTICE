class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int left =0;
        int right=sum;
        int ans =0;
        for(int i:nums)
        {
            if(i==0)
            {
                if(right-left==0)
                {
                    ans+=2;
                }
                else if (right-left==1||left-right==1)
                {
                    ans++;
                }
            }
            left+=i;
            right-=i;
        }
        return ans;
    }
};