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
    
    int max_rows;
    
    void findLargestValues(TreeNode* node, vector<int>& rows, int row) {
        if (node == NULL) return;
        max_rows = max(max_rows, row);
        if (node->val > rows[row]) rows[row] = node->val;
        findLargestValues(node->left, rows, row + 1);
        findLargestValues(node->right, rows, row + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        max_rows = 0;
        vector<int> rows;
        if (root == NULL) return rows;
        rows.resize(10001, INT_MIN);
        findLargestValues(root, rows, 0);
        rows.resize(max_rows + 1);
        return rows;
    }
};