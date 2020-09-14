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
    void construct(TreeNode*& root, vector<int>& preorder, int cur_idx, int stop_idx) {
        if (cur_idx >= preorder.size() || cur_idx >= stop_idx) return;
        root = new TreeNode(preorder[cur_idx]);
        // get all the elements that are going to be on the left subtree
        int max_idx = stop_idx;
        for (int i = cur_idx; i < preorder.size(); i++) {
            if (preorder[i] > root->val) {
                max_idx = i;
                break;
            }
        }
        construct(root->left, preorder, cur_idx + 1, max_idx);
        construct(root->right, preorder, max_idx, stop_idx);
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        construct(root, preorder, 0, preorder.size());
        return root;
    }
};