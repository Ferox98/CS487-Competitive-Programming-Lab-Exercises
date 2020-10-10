class Solution {
public:
    
    stack<vector<int>> island;
    vector<vector<bool>> discovered;
    vector<vector<int>> neighbors;
    
    bool inGrid(vector<vector<int>>& A, int x, int y) {
        if (x < 0 || x >= A.size() || y < 0 || y >= A[0].size()) {
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& A, int x, int y) {
        vector<int> c = {x, y};
        island.push(c);
        discovered[x][y] = true;
        for (auto& coord : neighbors) {
            int x_new = x + coord[0];
            int y_new = y + coord[1];
            if (inGrid(A, x_new, y_new) && A[x_new][y_new] == 1 && !discovered[x_new][y_new]) {
                dfs(A, x_new, y_new);
            }
        }
    }
    
    int grow(vector<vector<int>>& A) {
        int steps = 0;
        while(true) {
            stack<vector<int>> temp;
            while(!island.empty()) {
                vector<int> coord = island.top();
                island.pop();
                int x = coord[0], y = coord[1];
                discovered[x][y] = true;
                for (auto& neighbor : neighbors) {
                    int x_new = x + neighbor[0];
                    int y_new = y + neighbor[1];
                    if (inGrid(A, x_new, y_new) && A[x_new][y_new] == 1 && !discovered[x_new][y_new]) {
                        return steps;
                    }
                    else if (inGrid(A, x_new, y_new) && !discovered[x_new][y_new]) {
                        vector<int> c = {x_new, y_new};
                        temp.push(c);
                        discovered[x_new][y_new] = true;
                    }
                }
            }
            island = temp;
            steps++;
        }
        
        return steps;
    } 
    
    int shortestBridge(vector<vector<int>>& A) {
        discovered = vector<vector<bool>>(A.size(), vector<bool>(A[0].size(), false));
        neighbors = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        // discover the islands using bfs
        bool traversed = false;
        for (int x = 0; x < A.size(); x++) {
            for (int y = 0; y < A[x].size(); y++) {
                if (A[x][y] == 1 && !discovered[x][y]) {
                    dfs(A, x, y);
                    traversed = true;
                    break;
                }
            }
            if (traversed) break;
        }
        // for (auto& row : island) {
        //     for (auto& elem : row) 
        //         cout << elem << " , ";
        //     cout << endl;
        // }
        int min_bridge = grow(A);
        return min_bridge;
    }
};