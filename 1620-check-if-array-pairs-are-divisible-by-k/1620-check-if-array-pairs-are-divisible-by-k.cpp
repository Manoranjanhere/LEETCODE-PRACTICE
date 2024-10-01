class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> un;
        for(int i=0;i<n;i++)
        {
            un[((arr[i]%k)+k)%k]++;
        }
        for(auto i:un)
        {
            int st=i.first;
            int c=i.second;
            if(st==0)
            {
                if(c%2!=0)
                {
                    return false;
                }
            }
            else if(2*st==k)
            {
                if(c%2!=0)
                {
                    return false;
                }
            }
            else
            {
                int com = k-st;
                if(un[com]!=c)
                {
                    return false;
                }
            }
        }
        return true;
    }
};