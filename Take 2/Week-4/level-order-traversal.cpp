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
    
    int max_height;

    void dfs(TreeNode* node, int cur_level, map<TreeNode*, int>& level_map) {
        if (cur_level > max_height) max_height = cur_level;
        level_map[node] = cur_level;
        if (node->left != NULL)
            dfs(node->left, cur_level + 1, level_map);
        if (node->right != NULL)
            dfs(node->right, cur_level + 1, level_map);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        
        max_height = 0;
        map<TreeNode*, int> level_map;
        dfs(root, 1, level_map);
        res = vector<vector<int>>(max_height);
        for(auto& elem : level_map) {
            int idx = res.size() - elem.second;
            int val = elem.first->val;
            res[idx].push_back(val);
        }
        return res;
    }
};