class Solution {
public:
    
    vector<bool> preprocessed, traversed;
    
    bool preprocess(vector<vector<int>>& graph, int node, vector<bool>& hasApple, vector<bool>& subapple) {
        bool fin = false;
        preprocessed[node] = true;
        for (int i = 0; i < graph[node].size(); i++) {
            if (!preprocessed[graph[node][i]]) {
                bool has_subapple = preprocess(graph, graph[node][i], hasApple, subapple);
                if (has_subapple == true) fin = true;    
            }
        }
        if (fin == true) {
            subapple[node] = true;
            return true;
        }
        if (hasApple[node]) {
            subapple[node] = true;
            return true;
        } 
        subapple[node] = false;
        return false;
    }
    
    void traverse(vector<vector<int>>& graph, int node, int& seconds, vector<bool>& subapple) {
        traversed[node] = true;
        for (int i = 0; i < graph[node].size(); i++) {
            if (subapple[graph[node][i]] && !traversed[graph[node][i]]) {
                seconds++;
                traverse(graph, graph[node][i], seconds, subapple);
            }
        }
        if (node != 0)
            seconds++;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> subapple(edges.size() + 1, false);
        preprocessed = vector<bool>(edges.size() + 1, false);
        traversed = vector<bool>(edges.size() + 1, false);
        
        vector<vector<int>> graph(edges.size() + 1);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        bool res = preprocess(graph, 0, hasApple, subapple);
        int count = 0;
        if (res == false)
            return count;
        traverse(graph, 0, count, subapple);
        return count;
    }
};