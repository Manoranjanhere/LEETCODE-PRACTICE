class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> store(n);
        int ans =0;
        for(int i=0;i<n;i++)
        {
            for(char c: words[i])
            {
                store[i]|=(1<<(c-'a'));
            }
            for(int j=0;j<i;j++)
            {
                if(!(store[j]&store[i]))
                {
                    if((words[i].size()*words[j].size())>ans)
                    {
                        ans=words[i].size()*words[j].size();
                    }
                }
            }
        }
        return ans;
    }
};