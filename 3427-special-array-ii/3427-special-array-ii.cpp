class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = nums.size();
        vector<int> pref(n);
        int c=0;
        pref[0]=c;
        for(int i=1;i<n;i++)
        {
            if((nums[i]%2==0&&nums[i-1]%2==0)||(nums[i]%2==1&&nums[i-1]%2==1))
            {
                c++;
            }
            pref[i]=c;
            cout<<pref[i];
        }
        int sec=0;
        for(int i=0;i<queries.size();i++)
        {
            if(queries[i][0]==0)
            {
                sec=0;
            }
            else
            {
                sec=pref[queries[i][0]];
            }
            if((pref[queries[i][1]]-sec)!=0)
            {
                ans.push_back(false);
            }
            else
            {
                ans.push_back(true);
            }
        }
        return ans;
    }
};