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
    TreeNode* search(TreeNode* root, int val) {
        if (root == NULL) return root;
        if (root->val == val)
            return root;
        if (root->val < val) {// search it's right
            TreeNode* node = search(root->right, val);
            if (node != NULL)
                return node;
        }
        if (root->val > val) { // search it's left
            TreeNode* node = search(root->left, val);
            if (node != NULL)
                return node;
        }
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = search(root, val);
        return res;
    }
};