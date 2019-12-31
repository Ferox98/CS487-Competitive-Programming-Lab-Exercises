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
    void insertRecursive(TreeNode*& root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            return;
        }
        if (root->val > val) // go to the left
            insertRecursive(root->left, val);
        else if (root->val < val) 
            insertRecursive(root->right, val);
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertRecursive(root, val);
        return root;
    }
};