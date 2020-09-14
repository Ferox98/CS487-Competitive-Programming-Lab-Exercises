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
    
    void inOrderTraversal(TreeNode* node, vector<int>& nodes) {
        if (node == NULL) return;
        inOrderTraversal(node->left, nodes);
        nodes.push_back(node->val);
        inOrderTraversal(node->right, nodes);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        inOrderTraversal(root, nodes);
        for(int i = 1; i < nodes.size(); i++) {
            if(nodes[i] <= nodes[i - 1])
                return false;
        }
        return true;
    }
};