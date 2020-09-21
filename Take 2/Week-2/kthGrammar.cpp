class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 ) return 0;
        if (K % 2 == 0) {
            int par = kthGrammar(N - 1, K / 2);
            if (par == 0) return 1;
            return 0;
        }
        int par = kthGrammar(N - 1, (K + 1) / 2);
        if (par == 0) return 0;
        return 1;
    }
};