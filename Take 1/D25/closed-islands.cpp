class Solution {
public:
    
    bool isIsland(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& discovered, vector<vector<bool>>& island) {
        discovered[i][j] = true;
        if (i == grid.size() - 1 || j == grid[0].size() - 1 ||
           i == 0 || j == 0) {
            island[i][j] = false;
            return false;
        }
        vector<vector<int>> neighbors = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int k = 0; k < neighbors.size(); k++) {
            int new_i = i + neighbors[k][0];
            int new_j = j + neighbors[k][1];
            if (new_i < grid.size() && new_j < grid[0].size() && grid[new_i][new_j] == 0) {
               if(!discovered[new_i][new_j] && isIsland(grid, new_i, new_j, discovered, island) == false) {
                   island[i][j] = false;
                   return false;
               }
               else if (discovered[new_i][new_j] && island[new_i][new_j] == false) {
                   island[i][j] = false;
                   return false;
               }
            }
        }
        island[i][j] = true;
        return true;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> discovered(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<bool>> island(grid.size(), vector<bool>(grid[0].size(), true));
        int island_count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0 && !discovered[i][j]) {
                    bool is_island = isIsland(grid, i, j, discovered, island);
                    if (is_island) {
                        cout << "found an island at " << i << " , " << j << endl;
                        island_count++;
                    }
                }
            }
        }        
        return island_count;
    }
};