class Solution {
public:
    map<TreeNode*, int> val;
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (val.find(root) != val.end()) return val[root];
        int left = 0, right = 0;
        if (root->left != NULL) {
            left = rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != NULL) {
            right = rob(root->right->left) + rob(root->right->right);
        }
        int res = max(root->val + left + right, rob(root->left) + rob(root->right));
        val[root] = res;
        return res;
    }
};