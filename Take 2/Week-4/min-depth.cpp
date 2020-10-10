/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isLeaf(TreeNode* node) {
        if (node->left == NULL && node->right == NULL) return true;
        return false;
    }
    
    int findMinDepth(TreeNode* node, int cur_depth) {
        cur_depth++;
        if (node->left == NULL && node->right == NULL) {
            return cur_depth;
        }
        int left_depth = INT_MAX, right_depth = INT_MAX;
        if (node->left != NULL) {
            left_depth = findMinDepth(node->left, cur_depth);
        }
        if (node->right != NULL) {
            right_depth = findMinDepth(node->right, cur_depth);
        }
        return min(left_depth, right_depth);
    }
    
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int min_depth = findMinDepth(root, 0);
        return min_depth;
    }
};