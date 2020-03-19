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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 1));
        while(!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            int level = p.second; 
            TreeNode* node = p.first;
            if (level > res.size()) res.push_back(vector<int>(1, node->val));
            else
                res[level - 1].push_back(node->val);
            if (node->left != NULL) {
                q.push(pair<TreeNode*, int>(node->left, level + 1));
            }
            if (node->right != NULL) {
                q.push(pair<TreeNode*, int>(node->right, level + 1));
            }
        }
        return res;
    }
};