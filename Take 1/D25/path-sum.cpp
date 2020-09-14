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
    bool hasPath(TreeNode* cur_node, int cur_sum, int target) {
        if (cur_node == NULL) {
            return false;
        }
        cur_sum += cur_node->val;
        if (cur_node->left == NULL && cur_node->right == NULL) {
            if (cur_sum == target) {
                return true;
            }
            else {
                return false;
            }
        }
        
        if(cur_node->left != NULL) {
            bool res = hasPath(cur_node->left, cur_sum, target);
            if (res == true) {
                return true;
            }
        }
        if (cur_node->right != NULL) {
            return hasPath(cur_node->right, cur_sum, target);
        }
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPath(root, 0, sum);
    }
};