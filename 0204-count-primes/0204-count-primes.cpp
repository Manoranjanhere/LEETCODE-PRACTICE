class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;  // no primes < 2
        
        vector<int> seive(n, 1);
        seive[0] = seive[1] = 0;  // 0 and 1 are not prime

        for (int i = 2; i * i < n; i++) {
            if (seive[i] == 0) continue;
            int ind = i * i;
            while (ind < n) {
                seive[ind] = 0;
                ind += i;
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (seive[i] == 1) ans++;
        }
        return ans;
    }
};
