class Solution {
public:
    bool isParent(vector<int>& parents, int parent, int child) {
        if (parents[child] == -1) return false;
        if (parents[child] == parent) return true;
        return isParent(parents, parent, parents[child]);
    }
    
    bool cycleExists(vector<vector<int>>& graph, vector<int>& parents, vector<bool>& discovered, 
                     int start, queue<int>& schedule) {
        discovered[start] = true;
        for(int i = 0; i < graph[start].size(); i++) {
            int node = graph[start][i];
            parents[node] = start;
            if(discovered[node] && isParent(parents, node, start)) {
                return true;
            }
            else if (!discovered[node] && cycleExists(graph, parents, discovered, node, schedule)) {
                return true;
            }
        }
        schedule.push(start);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // convert the edge list to an adjacency list
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            int src = prerequisites[i][0];
            int dest = prerequisites[i][1];
            graph[src].push_back(dest);
        }
        vector<int> parents(numCourses, -1);
        vector<bool> discovered(numCourses, false);
        queue<int> schedule;
        bool cycle_exists = false;
        for (int i = 0; i < graph.size(); i++) {
            if(!discovered[i])
                cycle_exists = cycleExists(graph, parents, discovered, i, schedule);
        }
        vector<int> order;
        if (schedule.size() == numCourses) {
            while(!schedule.empty()) {
                order.push_back(schedule.front());
                schedule.pop();
            }
        }
        return order;
    }
};