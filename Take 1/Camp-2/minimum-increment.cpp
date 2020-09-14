class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int, int> counts;
        sort(A.begin(), A.end());
        int iterations = 0;
        for (int i = 0; i < A.size(); i++) {
            counts[A[i]]++;
            if(counts[A[i]] > 1) {
                iterations += A[i - 1] - A[i] + 1;
                A[i] = A[i - 1] + 1;
                counts[A[i]]++;
            }
        }
        return iterations;
    }
};