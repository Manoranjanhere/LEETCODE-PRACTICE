class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum=0;
        priority_queue<int> pq(nums.begin(),nums.end());
            while(k>0)
            {
                int top = pq.top();
                pq.pop();
                sum+=top;
                top=ceil(static_cast<double>(top)/3);
                pq.push(top);
                k--;
            }
        return sum;
    }
};