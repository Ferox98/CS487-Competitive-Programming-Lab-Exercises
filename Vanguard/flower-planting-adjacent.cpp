class Solution {
public:
    
    vector<vector<int>> constructGraph(vector<vector<int>>& paths, int n) {
        vector<vector<int>> graph(n);
        for (auto& p : paths) {
            graph[p[0] - 1].push_back(p[1] - 1);
            graph[p[1] - 1].push_back(p[0] - 1);
        }
        return graph;
    }
    
    bool dfs(vector<vector<int>>& graph, int cur_garden, vector<bool> discovered, vector<int>& sol) {
        vector<int> flowers = {1, 2, 3, 4};
        discovered[cur_garden] = true;
        for (auto& flower : flowers) {
            bool can_plant = true;
            for (auto& neighbor : graph[cur_garden]) {
                if (sol[neighbor] == flower) {
                    can_plant = false;
                    break;
                }
            }
            if (can_plant) {
                sol[cur_garden] = flower;
                bool has_undiscovered_neighbor = false;
                for (auto& neighbor : graph[cur_garden]) {
                    if (!discovered[neighbor]) {
                        has_undiscovered_neighbor = true;
                        bool path = dfs(graph, neighbor, discovered, sol);
                        if (path) return true;
                    }
                }
                if (!has_undiscovered_neighbor) return true;
            }
        }
        return false;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph = constructGraph(paths, n);
        vector<bool> discovered(n, false);
        bool solution_found = false;
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            if (res[i] == -1) {
                bool cur = dfs(graph, i, discovered, res);        
            }
        }
        return res;
    }
};