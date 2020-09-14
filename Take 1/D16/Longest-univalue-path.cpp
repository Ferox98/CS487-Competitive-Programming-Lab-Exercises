#include <map>
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
    int max_len = 0;
    void findPathLengths(TreeNode* root, int& streak) {
        if (root == NULL)
            return;
        cout << "root now is " << root->val << endl;
        if (root->left != NULL) {
            if (root->val == root->left->val) {
                streak++;
                if (streak > max_len)
                    max_len = streak;
                cout << "calling find->left. Streak now is " << streak << endl;
                findPathLengths(root->left, streak);
            }
            else {
                cout << "choosing alternate path" << endl;
                streak = 0;
                findPathLengths(root->left, streak);            
            }
        }
        if (root->right != NULL) {
            if (root->val == root->right->val) {
                streak++;
                if (streak > max_len)
                    max_len = streak;
                cout << "calling find->right. Streak now is " << streak << endl;
                findPathLengths(root->right, streak);
            }
            else {
                cout << "choosing alternate path" << endl;
                streak = 0;
                findPathLengths(root->right, streak);
            }
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        int streak = 0;
        findPathLengths(root, streak);
        return max_len;
    }
};