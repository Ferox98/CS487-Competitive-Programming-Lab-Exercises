#include <numeric>

class Solution {
public:
    int smallest = INT_MAX;
    void bst(vector<int>& nums, int low, int high, int threshold) {
        if (low >= high) return;
        int mid = (int)((low + high) / 2);
        vector<int> temp = nums;
        for (auto& i : temp) {
            int val = ceil((float)i / (float)mid);
            i = val;
        }
        int sum = accumulate(temp.begin(), temp.end(), 0);  

        if (sum <= threshold) {
            // check to the left of mid
            smallest = mid;
            bst(nums, low, mid, threshold);
            return;
        }
        // check to the right of mid
        if(low != mid)
            bst(nums, mid, high, threshold);

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        bst(nums, 1, 1000000, threshold);
        return smallest;
    }
};