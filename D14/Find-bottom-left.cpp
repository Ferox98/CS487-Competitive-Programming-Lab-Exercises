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
    int left_most = -1;
    int max_height = 0;
    void leftMostVal(TreeNode* root, int height) {
        if (root == NULL) return;
        if(height > max_height) {
            max_height = height;
            left_most = root->val;
        }
        if (root->left != NULL) 
            leftMostVal(root->left, height + 1);
        if (root->right != NULL) 
            leftMostVal(root->right, height + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        leftMostVal(root, 1);
        return left_most;
    }
};