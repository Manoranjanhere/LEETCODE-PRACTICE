class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>st(arr.begin(),arr.end());
        int c=2;;
        int mx=1;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sec = arr[j];
                int sum = arr[i]+sec;
                while(st.find(sum)!=st.end())
                {
                    c++;
                    int temp=sum;
                    sum+=sec;
                    sec=temp;
                }
                mx=max(mx,c);
                c=2;
            }
        }
        return(mx==2)?0:mx;
    }
};