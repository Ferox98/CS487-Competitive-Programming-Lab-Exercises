#include <algorithm>

bool isSorted(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) 
        if (vec[i] < vec[i - 1])
            return false;
    return true;            
}

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> k;
        int reverse_idx = A.size();
        while (!isSorted(A)) {
            // find the largest element
            int largest = A[0], largest_idx = 0;
            for (int i = 0; i < reverse_idx; i++) {
                if (A[i] > largest) {
                    largest = A[i];
                    largest_idx = i;
                }
            }
            // move it to the front
            reverse(A.begin(), A.begin() + largest_idx + 1);
            k.push_back(largest_idx + 1);
            // then move it to the back
            reverse(A.begin(), A.begin() + reverse_idx);
            k.push_back(reverse_idx);

            reverse_idx--;
        }
        return k;
    }
};