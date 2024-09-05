class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>ans;
        int m = rolls.size();
        int sm=0;
        for(int i=0;i<m;i++)
        {
            sm+=rolls[i];
        }
        int sn = mean*(m+n)-sm;
        if(sn>n*6||sn<n*1)
        {
            return ans;
        }
        else
        {
            int k=sn/n;
            sn%=n;
            for(int i=0;i<n;i++)
            {
                ans.push_back(k);
            }
            while(sn!=0)
            {
                for(int i=0;i<n;i++)
                {
                    if(sn==0)
                    {
                        break;
                    }
                    else
                    {
                        ans[i]+=1;
                        sn--;
                    }
                }
            }
        }
        return ans;
    }
};