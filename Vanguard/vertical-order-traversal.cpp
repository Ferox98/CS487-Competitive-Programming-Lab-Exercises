class Solution {
public:
    
    void dfs(map<int, vector<pair<int, TreeNode*>>>& pos, TreeNode* cur_node, int row, int col, int& max_col) {
        if (cur_node == NULL) return;
        max_col = max(max_col, col + 1);
        pos[col].push_back(pair<int, TreeNode*>(row, cur_node));
        dfs(pos, cur_node->left, row + 1, col - 1, max_col);
        dfs(pos, cur_node->right, row + 1, col + 1, max_col);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int max_col = 0;
        map<int, vector<pair<int, TreeNode*>>> pos;
        dfs(pos, root, 0, 0, max_col);
        vector<vector<int>> traversal;
        for (auto iter = pos.begin(); iter != pos.end(); iter++) {
            sort(iter->second.begin(), iter->second.end(), [](const auto& elem_1, const auto& elem_2) {
                if (elem_1.first == elem_2.first) {
                    return elem_1.second->val < elem_2.second->val;
                }
                return elem_1.first < elem_2.first;
            });
            vector<int> nodes;
            for (auto& elem : iter->second) {
                nodes.push_back(elem.second->val);
            }
            traversal.push_back(nodes);
        }
        return traversal;
    }
};