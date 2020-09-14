#include <stack>
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
    int addParents(TreeNode* root, TreeNode* p, queue<TreeNode*>& p_stack) {
        if (root == NULL) return -1;
        if (root->val == p->val) 
            return 0;
        int p_search = -1;
        if (root->val > p->val) { 
            p_search = addParents(root->left, p, p_stack);
            if(p_search == 0) {
                p_stack.push(root);
                return 0;
            }
        }
        if (root->val < p->val) {
            p_search = addParents(root->right, p, p_stack);
            if (p_search == 0) {
                p_stack.push(root);
                return 0;
            }
        }
        return -1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root)
            return root;
        queue<TreeNode*> p_queue, q_queue;
        int res = addParents(root, p, p_queue);
        res = addParents(root, q, q_queue);
        // which is the bigger stack?
        while (p_queue.size() > q_queue.size()) {
            if (p_queue.front() == q)
                return q;
            p_queue.pop();
        }
        while (q_queue.size() > p_queue.size()) {
            if (q_queue.front() == p)
                return p;
            q_queue.pop();
        }
        TreeNode* result = NULL;
        while (!p_queue.empty() && !q_queue.empty()) {
            TreeNode* p_top = p_queue.front(), *q_top = q_queue.front();
            if (p_top->val == q_top->val) {
                result = p_top;
                break;
            }
            p_queue.pop(), q_queue.pop();
        }
        return result;
    }
};