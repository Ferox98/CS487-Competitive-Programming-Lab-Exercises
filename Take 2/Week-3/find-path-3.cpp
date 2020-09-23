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
    
    vector<TreeNode*> leaves;
    map<TreeNode*, TreeNode*> parent;
    
    void findPaths(TreeNode* node, int sum, int cur_sum) {
        cur_sum += node->val;
        if (node->left == NULL && node->right == NULL) {
            if (cur_sum == sum) {
                leaves.push_back(node);
            }
            return;
        } 
        if (node->left != NULL) {
            parent[node->left] = node;
            findPaths(node->left, sum, cur_sum);
        }
        if (node->right != NULL) {
            parent[node->right] = node;
            findPaths(node->right, sum, cur_sum);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        parent[root] = NULL;
        findPaths(root, sum, 0);
        for(int i = 0; i < leaves.size(); i++) {
            TreeNode* node = leaves[i];
            stack<int> s;
            while (node != NULL) {
                s.push(node->val);
                node = parent[node];
            }
            vector<int> path;
            while(!s.empty()) {
                path.push_back(s.top());
                s.pop();
            }
            result.push_back(path);
        }
        return result;
    }
};