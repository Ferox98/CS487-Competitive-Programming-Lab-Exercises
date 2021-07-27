class Solution {
public:
    
    pair<int, int> dfs(int i, int parent, vector<vector<int>>& adj_list, vector<map<int, pair<int, int>>>& dp) {
        pair<int, int> p(0, 0);
        int nodes = 0, sum = 0;
        
        for (int j = 0; j < adj_list[i].size(); j++) {
            int node = adj_list[i][j];
            if (node != parent && dp.find(node) != dp.end()) {
                nodes += dp[i][node].first;
                sum += dp[i][node].second;
            }
            else if (node != parent) {
                pair<int, int> p_sub = dfs(node, i, adj_list, dp);
                nodes += (1 + p_sub.first);
                sum += (p_sub.first + p_sub.second + 1);
                dp[i][node] = pair<int, int>(p_sub.first + 1, p_sub.first + p_sub.second + 1);
                discovered[i][node] = true;
            }
        }
        if (nodes == 0) return p;
        return pair<int, int>(nodes, sum);
    }
    
    vector<vector<int>> initializeList(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj_list(n);
        for (int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        return adj_list;
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> sums;
        vector<vector<int>> adj_list = initializeList(edges, n);
        vector<map<int, pair<int, int>>> dp(n);
        
        for (int i = 0; i < n; i++) {
            sums.push_back(dfs(i, -1, adj_list, dp).second);
        }
        return sums;
    }
};