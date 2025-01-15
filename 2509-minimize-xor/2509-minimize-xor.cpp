class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2); 
        int result = 0;

        for (int i = 31; i >= 0 && n > 0; --i) {
            if ((num1 >> i) & 1) { 
                result |= (1 << i); 
                --n;
            }
        }

        for (int i = 0; i <= 31 && n > 0; ++i) {
            if (!((result >> i) & 1)) { 
                result |= (1 << i); 
                --n;
            }
        }

        return result;
    }
};
