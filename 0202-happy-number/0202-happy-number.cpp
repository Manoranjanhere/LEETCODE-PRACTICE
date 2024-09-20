class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(n);
        return solve(n,st);
    }
    bool solve(int n,unordered_set<int>& st)
    {
        long long sum=0;
        while(n>0)
        {
            int rem=n%10;
            sum+=pow(rem,2);
            n/=10;
        }
        if(sum==1)
        {
            return true;
        }
        else if(st.find(sum)!=st.end())
        {
            return false;
        }
        
            st.insert(sum);
            return solve(sum,st);
    }
};