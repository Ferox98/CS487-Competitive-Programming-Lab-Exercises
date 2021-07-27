class Solution {
public:
    
    int findSet(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return findSet(parent[x], parent);
    }
    
    void link(int i, int j, vector<int>& parent, vector<int>& rank) {
        if (rank[i] > rank[j]) {
            parent[j] = i;
        }
        else {
            parent[i] = j;
            if (rank[i] == rank[j]) {
                rank[j]++;
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int spare = 0;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto& connection : connections) {
            int i = connection[0];
            int j = connection[1];
            if (findSet(i, parent) != findSet(j, parent)) {
                link(findSet(i, parent), findSet(j, parent), parent, rank);
            }
            else {
                spare++;
            }
        }
        int num_connections = 0;
        for (int i = 1; i < n; i++) {
            if (findSet(i, parent) != findSet(0, parent) && spare > 0) {
                link(findSet(i, parent), findSet(0, parent), parent, rank);
                num_connections++;
                spare--;
            }
            else if (findSet(i, parent) != findSet(0, parent)) return -1;
        }
        return num_connections;
    }
};