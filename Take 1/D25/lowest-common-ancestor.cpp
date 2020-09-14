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
    
    int calcMaxDepth(TreeNode* node, TreeNode* parent, vector<TreeNode*>& parents) {
        if (node == NULL) {
            return 0;
        }
        int depth = 1 + max(calcMaxDepth(node->left, node, parents), calcMaxDepth(node->right, node, parents));
        parents[node->val] = parent;
        return depth;
    }
    
    void findLeaves(TreeNode* node, int cur_depth, int max_depth, vector<TreeNode*>& leaves) {
        if (node == NULL) {
            return;
        }
        cur_depth++;
        if(cur_depth == max_depth) {
            leaves.push_back(node);
            return;
        }
        findLeaves(node->left, cur_depth, max_depth, leaves);
        findLeaves(node->right, cur_depth, max_depth, leaves);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> parents(1001), leaves;
        int max_depth = calcMaxDepth(root, NULL, parents);
        findLeaves(root, 0, max_depth, leaves);
        // the current parent is the parent of one of the leaves
        TreeNode* cur_parent = leaves[0];
        bool solution_found = false;
        while(cur_parent != NULL) {
            solution_found = true;
            for(auto& leaf : leaves) {
                if (parents[leaf->val] != cur_parent && leaf != cur_parent) {
                    for (auto& leaf : leaves) leaf = parents[leaf->val];
                    solution_found = false;
                    break;
                }
            }
            if (solution_found) return cur_parent;
            cur_parent = parents[cur_parent->val];
        }
        return root;
    }
};