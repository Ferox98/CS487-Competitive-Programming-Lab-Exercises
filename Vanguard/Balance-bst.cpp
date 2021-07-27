class Solution {
public:
    
    void getNodes(TreeNode* cur_node, vector<TreeNode*>& nodes) {
        if (cur_node == NULL) return;
        getNodes(cur_node->left, nodes);
        nodes.push_back(cur_node);
        getNodes(cur_node->right, nodes);
    }
    
    TreeNode* balance(int low, int high, vector<TreeNode*>& nodes) {
        if (low > high) return NULL;
        int mid = (low + high) / 2;
        TreeNode* cur_node = nodes[mid];
        cur_node->left = balance(low, mid - 1, nodes);
        cur_node->right = balance(mid + 1, high, nodes);
        return cur_node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        getNodes(root, nodes);
        return balance(0, nodes.size() - 1, nodes);
    }
};