class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size();
        bool duplicate_found = false;
        int duplicate = -1;
        while (low < high) {
            int mid = (int)((low + high) / 2);

            // count the elements less than or equal to mid
            int count = 0;
            for (auto& i : nums) {
                if (i <= mid)
                    count++;
            } 
            if (count > mid) {
                // then there are duplicate elements in [1..mid]
                duplicate = mid;
                high = mid;
            }
            else if (low != mid) {
                // check for duplicates to the right of mid
                low = mid;
            }
            else
                break;
        }
        return duplicate;
    }
};