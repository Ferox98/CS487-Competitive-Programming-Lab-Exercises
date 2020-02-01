class Solution {
public:    
    
    int identifyGraphComponents(int node_idx, vector<vector<int>>& stones, vector<bool>& in_graph) {
        in_graph[node_idx] = true;
        int subgraph_size = 1;
        for (int i = 0; i < stones.size(); i++) {
            if ((stones[i][0] == stones[node_idx][0] || stones[i][1] == stones[node_idx][1])
               && !in_graph[i]) {
                subgraph_size += identifyGraphComponents(i, stones, in_graph);
            }
        }
        return subgraph_size;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> in_graph(stones.size());
        int max_removed = 0;
        for(int i = 0; i < stones.size(); i++) {
            if (!in_graph[i])
                max_removed += identifyGraphComponents(i, stones, in_graph) - 1;
        }
        return max_removed;
    }
};
