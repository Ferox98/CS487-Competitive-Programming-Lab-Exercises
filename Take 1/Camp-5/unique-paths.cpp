class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (m == 1 || n == 1) return 1;
        vector<vector<int>> matrix(m, vector<int>(n, 1));
        for(int i = matrix.size() - 2; i >= 0; i--) {
            for(int j = matrix[0].size() - 2; j >= 0; j--) {
                matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
            }
        }
        return matrix[0][0];
    }
};