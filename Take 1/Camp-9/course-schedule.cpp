class Solution {
public:
    vector<vector<int>> graph;
    
    bool isParent(vector<vector<int>>& graph, vector<int>& parents, int parent, int child) {
        if(parents[child] == -1) return false;
        if (parents[child] == parent) return true;
        return isParent(graph, parents, parent, parents[child]);
    }
    
    bool cycleExists(vector<vector<int>>& graph, vector<bool>& discovered, vector<int>& parents, int start) {
        discovered[start] = true;
        for(int i = 0; i < graph[start].size(); i++) {
            int node = graph[start][i];
            parents[node] = start;
            if (discovered[node] && isParent(graph, parents, node, start)) {
                return true;
            }
            if(!discovered[node] && cycleExists(graph, discovered, parents, node)) 
                return true;
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        // convert the edge list to an adjacency list
        for(int i = 0; i < prerequisites.size(); i++) {
            int src = prerequisites[i][0];
            int dest = prerequisites[i][1];
            graph[src].push_back(dest);
        }
        // perform dfs to detect if there are any cycles in the graph
        bool cycle_exists = false;
        vector<bool> discovered(numCourses, false);
        vector<int> parents(numCourses, -1);
        for (int i = 0; i < numCourses; i++) {
            cycle_exists = cycleExists(graph, discovered, parents, i);
            if (cycle_exists) return false;
        }
        return true;
    }
};