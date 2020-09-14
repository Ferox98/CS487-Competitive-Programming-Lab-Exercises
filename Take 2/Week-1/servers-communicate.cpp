class Solution {
public:    

    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(), 0);
        vector<int> cols(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        int con_servers = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
                    con_servers++;
                }
            }
        }
        return con_servers;
    }
};