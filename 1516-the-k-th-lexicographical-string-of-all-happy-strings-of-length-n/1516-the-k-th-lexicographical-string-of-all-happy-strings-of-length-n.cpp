class Solution {
public:
    string getHappyString(int n, int k) {
        string curr ="";
        vector<string> happy;
        gen(n,curr,happy);
        if(happy.size()<k)return "";
        sort(happy.begin(),happy.end());
        return happy[k-1];
    }
    void gen(int n, string curr,vector<string> &happy)
    {
        if(curr.size()==n)
        {
            happy.push_back(curr);
            return;
        }
        for(char c='a';c<='c';c++)
        {
            if(curr.size()>0&&curr.back()==c)
            {
                continue;
            }
            gen(n,curr+c,happy);
        }
    }
};