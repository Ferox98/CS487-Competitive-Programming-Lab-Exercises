class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j =  0; j < matrix[i].size(); j++) {
                if (j == 0) {
                    if (matrix[i].size() == 1) {
                        matrix[i][j] += matrix[i - 1][j];
                    }
                    else {
                        matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                    }
                }
                else if (j == matrix[i].size() - 1) {
                    matrix[i][j] += min(matrix[i- 1][j - 1], matrix[i - 1][j]);
                }
                else {
                    matrix[i][j] += min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i - 1][j + 1]));
                }
            }
        }
        int last_row = matrix.size() - 1;
        return *min_element(matrix[last_row].begin(), matrix[last_row].end());
    }
};