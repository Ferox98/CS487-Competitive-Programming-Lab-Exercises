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
    int sum = 0;
    
    void dfs(TreeNode* root, int L, int R) {
        if (root == NULL)
            return;
        if (root->val < L) {
            // check the node to it's right
            dfs(root->right, L, R);
            return; 
        }
        if (root->val > R) {
            // check the node to it's left
            dfs(root->left, L, R);
            return;
        }
        if (root->val >= L && root->val <= R) {
            sum += root->val;
            dfs(root->left, L, R);
            dfs(root->right, L, R);
            return;
        }
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
          dfs(root, L, R);
          return sum;  
    }
};