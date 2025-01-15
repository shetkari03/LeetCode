class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);
        int res = 0;

        // Prioritize setting bits of num1 that are already 1
        for (int i = 31; i >= 0 && count; i--) {
            if (num1 & (1 << i)) {
                count--;
                res |= (1 << i);
            }
        }

        // Fill in remaining bits with 0s in num1
        for (int i = 0; i < 32 && count; i++) {
            if ((num1 & (1 << i)) == 0) {
                count--;
                res |= (1 << i);
            }
        }

        return res;
    }
};