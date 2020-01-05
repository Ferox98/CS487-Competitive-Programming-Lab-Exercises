#include <algorithm>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int j = 1; j < nums.size(); j++) {
            int key = nums[j];
            int i = j - 1;
            while (i >= 0 && nums[i] > key) {
                nums[i + 1] = nums[i];
                i--;
            }
            nums[i + 1] = key;
        }
    }
};