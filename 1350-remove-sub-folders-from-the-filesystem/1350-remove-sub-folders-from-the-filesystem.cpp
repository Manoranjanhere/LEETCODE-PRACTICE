class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        unordered_set<string> a;
        vector<string> ans;
        sort(folder.begin(),folder.end());
        for(int i=0;i<n;i++)
        {
            string b="";
            int c=0;
            for(int j=0;j<folder[i].size();j++)
            {
                b+=folder[i][j];
                if(j==folder[i].size()-1||folder[i][j+1]=='/')
                {
                    if(a.find(b)!=a.end())
                    {
                        c++;
                        break;
                    }
                }
            }
            if(c==0)
            {
                ans.push_back(folder[i]);
                a.insert(folder[i]);
            }
        }
        return ans;
    }
};