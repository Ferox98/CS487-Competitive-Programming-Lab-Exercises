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
    bool similar = true;
    void checkSame(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return;
        if (p == NULL && q != NULL) {
            similar = false;
            return;
        }
        if (p != NULL && q == NULL) {
            similar = false;
            return;
        }
        if (p->val != q->val) {
            similar = false;
            return;
        }
        checkSame(p->left, q->left);
        if(similar == false) return;
        checkSame(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        checkSame(p, q);
        return similar;
    }
};