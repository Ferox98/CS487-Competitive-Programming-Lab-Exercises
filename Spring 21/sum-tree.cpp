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
    int sumNumbers(TreeNode *root){
        return dfs(root, 0); 
    }
    
    int dfs(TreeNode *root, int sum) {
        if (!root) return 0;  
        int new_sum = sum * 10 + root->val; 
        if (!root->left && !root->right) return new_sum;
		return dfs(root->left, new_sum) + dfs(root->right, new_sum);
    }

};