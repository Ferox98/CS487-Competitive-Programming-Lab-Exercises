class Solution {
public:
    
    vector<vector<int>> constructGraph(vector<vector<int>>& richer, int n) {
        vector<vector<int>> graph(n);
        for (auto& p : richer) {
            graph[p[1]].push_back(p[0]);
        }
        return graph;
    }
    
    int bfs(vector<vector<int>>& graph, int start, vector<int>& quiet) {
        queue<int> q;
        q.push(start);
        int min_quiet = quiet[start];
        int res = start;
        vector<bool> discovered(quiet.size(), false);
        while (!q.empty()) {
            int cur_person = q.front();
            discovered[cur_person] = true;
            q.pop();
            if (quiet[cur_person] < min_quiet) {
                min_quiet = quiet[cur_person];
                res = cur_person;
            }
            for (int i = 0; i < graph[cur_person].size(); i++) {
                if (!discovered[graph[cur_person][i]])
                    q.push(graph[cur_person][i]);
            }
        }
        return res;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> graph = constructGraph(richer, quiet.size());
        vector<int> answer(quiet.size());
        for (int i = 0; i < quiet.size(); i++) {
            answer[i] = bfs(graph, i, quiet);
        }
        return answer;
    }
};