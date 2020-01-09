class Solution {
public:
    
    int trailingZeroes(int n) {
        long long count = 0;
        for(long long i = 5; (n / i) > 0; i *= 5) {
            count += (long long) n / i;
        }
        return count;
    }
};