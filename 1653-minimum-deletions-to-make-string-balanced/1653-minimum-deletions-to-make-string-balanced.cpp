class Solution {
public:
    int minimumDeletions(string s) {
        int ans =0;
        int bc=0;
        for(int i:s)
        {
            if(i=='b')bc++;
            else ans=min(ans+1,bc);
        }
        return ans;
    }
};