class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int candidate=0;
       for(int num:nums)
       {
        if(c==0)
        {
            candidate=num;
        }
        if(num==candidate)
        {
            c++;
        }
        else
        {
            c--;
        }
       }
        return candidate;
    }
};