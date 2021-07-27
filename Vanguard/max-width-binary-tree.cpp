class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, pair<long, long>>> q;
        long long start = 1;
        q.push(pair<TreeNode*, pair<long long, long long>>(root, pair<long long, long long>(start, start)));
        long long prev_level = 1, prev_idx = 1;
        long long max_width = 0;
        while (!q.empty()) {
            pair<TreeNode*, pair<long long, long long>> front = q.front();
            TreeNode* cur_node = front.first;
            q.pop();
            long long node_idx = front.second.first;
            long long node_level = front.second.second;
           // cout << cur_node->val << " , " << node_idx << " , " << node_level << endl;
            if (node_level > prev_level) {
                prev_level = node_level;
                prev_idx = node_idx;
            }
            long long cur_width = node_idx - prev_idx + 1;
            //cout << cur_width << " , " << node_idx << " , " << prev_idx << endl;
            max_width = max(max_width, cur_width);
            if (cur_node->left) {
                q.push(pair<TreeNode*, pair<long long, long long>>(cur_node->left, pair<long long, long long>(node_idx * 2, node_level + 1)));
            }
            if (cur_node->right) {
                q.push(pair<TreeNode*, pair<long long, long long>>(cur_node->right, pair<long long, long long>(node_idx * 2 + 1, node_level + 1)));
            }
        }
        return max_width;
    }
};