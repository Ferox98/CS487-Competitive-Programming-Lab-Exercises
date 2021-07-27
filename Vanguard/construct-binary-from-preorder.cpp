class Solution {
public:
    
    TreeNode* helper(int& cur_idx, unordered_map<int, int>& idx, vector<int>& preorder, vector<int>& inorder, int lo, int high) {
        if (lo > high || cur_idx >= preorder.size()) {
            cur_idx--;
            return NULL;
        };
        int cur_val = preorder[cur_idx];
        TreeNode* cur_node = new TreeNode(cur_val);
        int node_idx = idx[cur_val];
        cur_idx++;
        cur_node->left = helper(cur_idx, idx, preorder, inorder, lo, node_idx - 1);
        cur_idx++;
        cur_node->right = helper(cur_idx, idx, preorder, inorder, node_idx + 1, high);
        return cur_node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int cur_idx = 0;
        unordered_map<int, int> idx;
        for (int i = 0; i < inorder.size(); i++) { 
            idx[inorder[i]] = i;
        }
        TreeNode* root = helper(cur_idx, idx, preorder, inorder, 0, inorder.size() - 1);
        return root;
    }
};