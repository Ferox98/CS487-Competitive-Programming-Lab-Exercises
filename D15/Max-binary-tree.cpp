/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumTree(vector<int>& nums, int low, int high) {
        if (low >= high)
            return NULL;
        // get where to split the subarray
        int mid = low, max = nums[low];
        for (int i = low; i < high; i++) { 
            if (nums[i] > max) {
                max = nums[i];
                mid = i;
            }
        }
        TreeNode* root = new TreeNode(nums[mid]);
        // recursive calls to follow
        root->left = constructMaximumTree(nums, low, mid);
        root->right = constructMaximumTree(nums, mid + 1, high);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = constructMaximumTree(nums, 0, nums.size());  
        return root;
    }
};