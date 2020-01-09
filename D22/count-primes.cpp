class Solution {
public:
    map<long long, bool> marked;
        
    int sieve(int maximum) {
        vector<bool> marked(maximum, false);
        int composite_count = 0;
        for(long long i = 2; i < sqrt(maximum); i++) {
            if (marked[i]) continue;
            for(long long j = i * i; j < maximum; j += i) {
                if(marked[j]) continue;
                composite_count++;
                marked[j] = true;         
            }
        }
        return maximum - composite_count - 2;
    }
    
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        int count = sieve(n);
        return count;
    }
};