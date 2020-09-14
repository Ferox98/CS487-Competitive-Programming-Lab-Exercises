class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 3;
        int product = 1;
        while (n < 4) {
            product *= 3;
            n -= 3;
        }
        product *= n;
        return product;
    }
};