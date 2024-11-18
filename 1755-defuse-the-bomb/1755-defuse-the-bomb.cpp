class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n = code.size();
        if(k==0)
        {
            for(int i=0;i<n;i++)
            {
                ans.push_back(0);
            }
            return ans;
        }
        if(k>0)
        {
            int sum=0;
            for(int i=0;i<k;i++)
            {
                sum+=code[i];
            }
            for(int i=0;i<n;i++)
            {
                sum=sum-code[i]+code[(i+k)%(n)];
                ans.push_back(sum);
            }
            return ans;
        }
        else
        {
            k*=-1;
            int sum=0;
            for(int i=n-1;i>=n-k;i--)
            {
                sum+=code[i];
            }
            for(int i=0;i<n;i++)
            {
                ans.push_back(sum);
                sum=sum+code[i]-code[(i+n-k)%n];
            }
        }
        return ans;
    }
};