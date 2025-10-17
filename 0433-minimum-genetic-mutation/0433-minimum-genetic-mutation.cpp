class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> vis(bank.begin(),bank.end());
        int ans =0;
        string mutation= "ACGT";
        queue<string> q;
        q.push(startGene);
        while(q.size())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                if(it==endGene)return ans;
                string x=it;
                for(int i=0;i<8;i++)
                {
                    char ch=it[i];
                    for(auto c:mutation)
                    {
                        if(ch==c)continue;
                        x[i]=c;
                        if(vis.find(x)!=vis.end())
                        {
                            q.push(x);
                            vis.erase(x);
                        }
                    }
                    x[i]=ch;
                }
            }
            ans++;
        }
        return -1;
    }
};