class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        if(nums.size()<2)return 0;
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        int c=0;
        while(!pq.empty()&&pq.top()<k)
        {
            c++;
            long long k1=pq.top();
            pq.pop();
            long long k2=pq.top();
            pq.pop();
            if(pq.empty())
            {
                return c;
            }
            long long sum=min(k1,k2)*2+max(k1,k2);
            cout<<sum<<" ";
            pq.push(sum);
        }
        return c;
    }
};