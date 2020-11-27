class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> nodes(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int target = edges[i][1];
            nodes[target] = 1;
        }
        vector<int> res;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == 0) res.push_back(i);
        }
        return res;
    }
};