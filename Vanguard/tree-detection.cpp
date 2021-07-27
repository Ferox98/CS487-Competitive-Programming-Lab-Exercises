bool hasCycle(vector<int>& left, vector<int>& right, int cur_node, unordered_map<int, bool>& discovered) {
    if (cur_node >= left.size() || cur_node == -1) return false;
    if (discovered[cur_node]) {
        return true;
    }
    discovered[cur_node] = true;
    return (hasCycle(left, right, left[cur_node], discovered) || hasCycle(left, right, right[cur_node], discovered));
}

bool solve(vector<int>& left, vector<int>& right) {
    unordered_map<int, bool> discovered;
    vector<int> parent(left.size(), -1);
    for (int i = 0; i < left.size(); i++) {
        if (left[i] != -1) parent[left[i]] = i;
        if (right[i] != -1) parent[right[i]] = i;
    }
    int root = -1;
    for (int i = 0; i < left.size(); i++) {
        if (parent[i] == -1) {
            if (root != -1) return false;
            root = i;
        }
    }
    if (root == -1) return false;
    bool cycle = hasCycle(left, right, root, discovered);   
    if (cycle) return false;
    for (int i = 0; i < left.size(); i++) {
        if (!discovered[i]) return false;
    }
    return true;
}