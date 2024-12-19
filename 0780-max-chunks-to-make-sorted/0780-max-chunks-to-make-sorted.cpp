class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>pref_sum;
        int sum=0;
        for(int i:arr)
        {
            sum+=i;
            pref_sum.push_back(sum);
        }
        for(int i:pref_sum)
        {
            cout<<i<<" ";
        }
        sort(arr.begin(),arr.end());
        int c=0;
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(pref_sum[i]==sum)
            {
                c++;
            }
        }
        return c;
    }

};