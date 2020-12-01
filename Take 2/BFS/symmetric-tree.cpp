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
    bool isSymmetric(TreeNode* root) {
        vector<pair<TreeNode*, int>> q;
        int cur_level = 0;
        q.push_back(pair<TreeNode*, int>(root, cur_level));
        int idx = 0;
        while (idx < q.size()) {
            pair<TreeNode*, int> p = q[idx];
            TreeNode* node = p.first;
            int level = p.second;
            if (level != cur_level) {
                cur_level = level;
                int start = idx, end = q.size() - 1;
                
                bool similar = true;
                while (start < end) {
                    TreeNode* start_node = q[start].first;
                    TreeNode* end_node = q[end].first;
                    if (start_node == NULL && end_node == NULL){
                        start++;
                        end--;
                        continue;
                    }
                    else if (start_node == NULL || end_node == NULL) {
                        similar = false;
                        break;
                    }
                    if (start_node->val != end_node->val) {
                        similar = false;
                        break;
                    }
                    start++;
                    end--;
                }
                if (!similar) return false;
            }
            if (node == NULL) {
                idx++;
                continue;
            }
            if (node->left != NULL) {
                q.push_back(pair<TreeNode*, int>(node->left, level + 1));
            }
            else {
                q.push_back(pair<TreeNode*, int>(NULL, level + 1));
            }
            if (node->right != NULL) {
                q.push_back(pair<TreeNode*, int>(node->right, level + 1));
            }
            else {
                q.push_back(pair<TreeNode*, int>(NULL, level + 1));
            }
            idx++;
        }
        return true;
    }
};