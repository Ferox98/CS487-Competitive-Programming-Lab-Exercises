class Solution {
public:
    
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        int counter = 0;
        for (long long i = 2; i < n; i++) {
            if (prime[(int) i]) {
                counter++;
                long long start = i * i;
                while (start < n) {
                    prime[(int) start] = false;
                    start += i;
                }
            }
        }
        return counter;
    }
};