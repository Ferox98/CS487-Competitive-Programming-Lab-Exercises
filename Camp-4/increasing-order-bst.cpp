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

    void getSortedList(TreeNode* node, vector<TreeNode*>& node_list) {
        if (node == NULL) return;
        getSortedList(node->left, node_list);
        node->left = NULL;
        node_list.push_back(node);
        getSortedList(node->right, node_list);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> node_list;
        getSortedList(root, node_list);
        for(int i = 0; i < node_list.size() - 1; i++) {
            node_list[i]->right = node_list[i + 1];
        }
        cout << endl;
        return node_list[0];
    }
};