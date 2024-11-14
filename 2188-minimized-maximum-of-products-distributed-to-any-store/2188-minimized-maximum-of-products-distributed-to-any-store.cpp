class Solution {
public:
    static inline bool f(int x, vector<int>& quantities, int n){
        int sum=0;
        for(int a: quantities)
            sum+=(a+x-1)/x;// ceil(a/x)
        return sum>n;
    }
    static int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1, r=100000, m;
        while(l<r){
            m=(l+r)/2;
            if (f(m, quantities, n)) l=m+1;
            else r=m;
        } 
        return l;
        
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();