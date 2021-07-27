class BSTIterator {
public:
    
    vector<TreeNode*> nodes;
    int cur_idx;
    
    void getNodes(TreeNode* cur_node) {
        if (cur_node == NULL) return;
        getNodes(cur_node->left);
        nodes.push_back(cur_node);
        getNodes(cur_node->right);
    }
    
    BSTIterator(TreeNode* root) {
        getNodes(root);    
        cur_idx = 0;
    }
    
    int next() {
        cur_idx++;
        return nodes[cur_idx - 1]->val;
    }
    
    bool hasNext() {
        return cur_idx < nodes.size();
    }
};
