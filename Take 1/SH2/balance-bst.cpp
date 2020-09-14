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
    
    // do in order traversal to get a sorted vector of nodes
    void dfs(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node == NULL) return;
        if (node->left != NULL) dfs(node->left, nodes);
        nodes.push_back(node);
        if (node->right != NULL) dfs(node->right, nodes);
    }
    
    TreeNode* constructBST(vector<TreeNode*>& nodes, int low, int high) {
        if (low > high) return NULL;
        int idx = (low + high) / 2;
        TreeNode* root = nodes[idx];
        root->left = constructBST(nodes, low, idx - 1);
        root->right = constructBST(nodes, idx + 1, high);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        dfs(root, nodes);
        TreeNode* new_root = constructBST(nodes, 0, nodes.size() - 1);
        return new_root;
    }
};