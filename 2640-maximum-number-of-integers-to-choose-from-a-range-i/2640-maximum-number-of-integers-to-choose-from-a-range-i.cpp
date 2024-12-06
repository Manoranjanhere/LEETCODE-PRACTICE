class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int c=0;
        int s = banned.size();
        unordered_set<int> a(banned.begin(),banned.end());
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(!a.count(i))
            {
                sum+=i;
                if(sum>maxSum)
                {
                    break;
                }
                c++;

            }
        }
        return c;
    }
};