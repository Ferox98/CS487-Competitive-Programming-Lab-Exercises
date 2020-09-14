class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int num = 0;
        for(int i = 0; i < K; i++) {
            num = num * 10 + 1;
            num %= K;
            if (num == 0) return (i + 1);
        }
        return -1;
    }
};