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
    int sumEvenGrandparentAux(TreeNode* node, int grandparent, int parent) {
        if (node == NULL) return 0;
        int sum = 0;
        if (grandparent != -1 && grandparent % 2 == 0) {
            sum += node->val;    
        }
        sum += sumEvenGrandparentAux(node->left, parent, node->val);
        sum += sumEvenGrandparentAux(node->right, parent, node->val);
        return sum;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum = sumEvenGrandparentAux(root, -1, -1);
        return sum;
    }
};