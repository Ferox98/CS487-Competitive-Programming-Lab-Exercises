class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool monotone_increasing = true, monotone_decreasing = true;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) monotone_increasing = false;
            else if (A[i] < A[i - 1]) monotone_decreasing = false;
            if (!monotone_increasing && !monotone_decreasing) return false;
        }
        return true;
    }
};