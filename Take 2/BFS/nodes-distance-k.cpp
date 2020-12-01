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
    
    vector<vector<int>> createGraph(TreeNode* root) {
        vector<vector<int>> graph(501);
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            TreeNode* cur_node = nodes.front();
            nodes.pop();
            int cur_val = cur_node->val;
            if (cur_node->left != NULL) {
                // insert an undirected edge between node and it's child
                int left_val = cur_node->left->val;
                graph[cur_val].push_back(left_val);
                graph[left_val].push_back(cur_val);
                nodes.push(cur_node->left);
            }
            if (cur_node->right != NULL) {
                int right_val = cur_node->right->val;
                graph[cur_val].push_back(right_val);
                graph[right_val].push_back(cur_val);
                nodes.push(cur_node->right);
            }
        }
        return graph;
    }
    
    vector<int> bfs(TreeNode* target, int K, vector<bool>& discovered, vector<vector<int>>& graph) {
        queue<vector<int>> nodes;
        nodes.push({target->val, 0});
        vector<int> k_nodes;
        discovered[target->val] = true;
        while(!nodes.empty()) {
            vector<int> front = nodes.front();
            nodes.pop();
            int cur_node = front[0];
            int distance = front[1];
            for (int i = 0; i < graph[cur_node].size(); i++) {
                int neighbor = graph[cur_node][i];
                if (!discovered[neighbor]) {
                    discovered[neighbor] = true;
                    if (distance + 1 == K) {
                        k_nodes.push_back(neighbor);
                        continue;
                    }
                    nodes.push({neighbor, distance + 1});
                }
            }
        }
        return k_nodes;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0) return {target->val};
        vector<bool> discovered(501, false);
        vector<vector<int>> graph = createGraph(root);
        vector<int> nodes = bfs(target, K, discovered, graph);
        return nodes;
    }
};