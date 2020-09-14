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
    void dfs(TreeNode* node, vector<int>& res, int level) {
        if (node == NULL) return;
        if (res.size() <= level) {
            res.push_back(node->val);
        }
        dfs(node->right, res, level + 1);
        dfs(node->left, res, level + 1);
    }
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};