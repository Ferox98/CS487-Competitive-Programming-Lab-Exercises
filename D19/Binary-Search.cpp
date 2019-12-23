class Solution {
public:
    
    int searchRecursive(vector<int>& nums, int small, int large, int target) {
        if (nums[small] == target) return small;
        if (small >= large) return -1;
        if (nums[large] == target) return large;
        int mid = (int) ((small + large) / 2);
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            int res = searchRecursive(nums, small, mid - 1, target);
            if (res == -1 || nums[res] == target) 
                return res;
        }
        else if (nums[mid] < target) {
            int res = searchRecursive(nums, mid + 1, large, target);
            if (res == -1 || nums[res] == target)
                return res;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int res = searchRecursive(nums, 0, nums.size() - 1, target);
        return res;
    }
};