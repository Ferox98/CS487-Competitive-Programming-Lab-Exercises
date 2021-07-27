class Solution {
public:
    
    void flipNode(TreeNode* cur_node) {
        TreeNode* temp = cur_node->left;
        cur_node->left = cur_node->right;
        cur_node->right = temp;
    }
    
    bool isFlipped(TreeNode* cur_node, int cur_idx, vector<int>& voyage) {
        if (cur_idx < voyage.size() && cur_node->left != NULL && cur_node->right != NULL && cur_node->right->val == voyage[cur_idx]) {
            return true;
        }
        return false;
    }
    
    void dfs(TreeNode* cur_node, int& cur_idx, vector<int>& voyage, vector<int>& flips) {
        if (cur_idx >= voyage.size() || cur_node == NULL) return;
        if (cur_node->val != voyage[cur_idx]) {
            vector<int> res = { -1 };
            flips = res;
            return;
        }
        cur_idx++;
        if (isFlipped(cur_node, cur_idx, voyage)) {
            flipNode(cur_node);
            flips.push_back(cur_node->val);
        }
        if (cur_idx < voyage.size() && cur_node->left != NULL && voyage[cur_idx] == cur_node->left->val) {
            dfs(cur_node->left, cur_idx, voyage, flips);
        }
        if (cur_idx < voyage.size() && cur_node->right != NULL && voyage[cur_idx] == cur_node->right->val) {
            dfs(cur_node->right, cur_idx, voyage, flips);
        }
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flips;
        int cur_idx = 0;
        dfs(root, cur_idx, voyage, flips);
        if (cur_idx < voyage.size()) {
            vector<int> res = { -1 };
            return res;
        }
        return flips;
    }
};