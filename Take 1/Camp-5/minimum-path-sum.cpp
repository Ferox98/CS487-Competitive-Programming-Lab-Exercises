class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        for (int i = grid.size() - 1; i >= 0; i--) {
            for(int j = grid[i].size() - 1; j >= 0; j--) {
                if (i == grid.size() - 1) {
                    if (j != grid[i].size() - 1) grid[i][j] += grid[i][j + 1];
                }
                else if (j == grid[i].size() - 1) {
                    if (i != grid.size() - 1) grid[i][j] += grid[i + 1][j];
                }
                else {
                    grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
                }
            }
        }
        return grid[0][0];
    }
};