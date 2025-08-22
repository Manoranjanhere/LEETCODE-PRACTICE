class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<pair<int,string>> words2;
        for(string s:words)
        {
            words2.push_back({s.size(),s});
        }
        sort(words2.begin(),words2.end());
        vector<int>dp(n,1);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(words2[j].second.size()-words2[i].second.size()==1)
                {
                    bool notfound=false;
                    int ind =0;
                    int count=0;
                    for(int k=0;k<words2[j].second.size();k++)
                    {
                        if(words2[j].second[k]!=words2[i].second[ind])
                        {
                            count++;
                            if(count>=2)
                            {
                                notfound=true;
                                break;
                            }
                        }
                        else
                        {
                            ind++;
                        }
                    }
                    if(!notfound)
                    {
                        dp[j]=max(dp[j],dp[i]+1);
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};