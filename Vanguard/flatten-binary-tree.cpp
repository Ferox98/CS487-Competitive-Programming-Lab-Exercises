class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left == NULL) return;
        TreeNode* right_subtree = root->right;
        root->right = root->left;
        root->left = NULL;
        if (right_subtree == NULL) return;
        TreeNode* iter = root->right;
        while (iter->right != NULL) {
            iter = iter->right;
        }
        iter->right = right_subtree;
    }
};