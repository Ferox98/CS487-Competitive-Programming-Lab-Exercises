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
    void mergeDFS(TreeNode* t1, TreeNode* t2, TreeNode*& t3) {
        if (t1 == NULL && t2 == NULL)
            return;
        if (t1 == NULL && t2 != NULL) {
            t3 = t2;
            mergeDFS(t1, t2->left, t3->left);
            mergeDFS(t1, t2->right, t3->right);
        }
        else if (t1 != NULL && t2 == NULL) {
            t3 = t1;
            mergeDFS(t1->left, t2, t3->left);
            mergeDFS(t1->right, t2, t3->right);
        }
        else {
            t3 = new TreeNode(t1->val + t2->val);
            mergeDFS(t1->left, t2->left, t3->left);
            mergeDFS(t1->right, t2->right, t3->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* t3 = NULL;
        mergeDFS(t1, t2, t3);
        return t3;
    }
};