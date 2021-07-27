class Solution {
public:
    
    int findSet(int x, vector<int>& parent) {
        if (parent[x] == x) {
            return x;
        }
        return findSet(parent[x], parent);
    }
    
    void link(int x, int y, vector<int>& parent, vector<int>& rank) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> sol;
        vector<int> parent(1001);
        vector<int> rank(1001, 0);
        
        for (int i = 0; i < 1000; i++) parent[i] = i;
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            if (findSet(x, parent) == findSet(y, parent)) {
                sol = {x, y};
                break;
            }
            link(findSet(x, parent), findSet(y, parent), parent, rank);
        }
        return sol;
    }
};