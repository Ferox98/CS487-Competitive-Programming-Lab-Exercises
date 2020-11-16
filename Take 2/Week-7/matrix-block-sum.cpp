#include <algorithm>
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> sums(mat.size(), vector<int>(mat[0].size(), 0));
        sums[0][0] = mat[0][0];
        for (int i = 1; i < mat[0].size(); i++) {
            sums[0][i] = sums[0][i - 1] + mat[0][i];
        }
        for (int i = 1; i < mat.size(); i++) {
            sums[i][0] = sums[i - 1][0] + mat[i][0];
        }
        
        for (int i = 1; i < mat.size(); i++) {
            for (int j = 1; j < mat[i].size(); j++) {
                sums[i][j] = mat[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat[r].size(); c++) {
                int i_start = max(0, r - K);
                int param_1 = r + K, param_2 = mat.size() - 1;
                int i_end = min(param_1, param_2);
                int j_start = max(0, c - K);
                param_1 = c + K, param_2 = mat[r].size() - 1;
                int j_end = min(param_1, param_2);
               
                int total_sum = sums[i_end][j_end];
                int top_rect = i_start == 0 ? 0 : sums[i_start - 1][j_end];
                int left_rect = j_start == 0 ? 0 : sums[i_end][j_start - 1];
                int top_left = 0;
                if (top_rect > 0 && left_rect > 0) {
                    top_left = sums[i_start - 1][j_start - 1];
                }
                res[r][c] = total_sum - top_rect - left_rect + top_left;
            }
        }
        return res;
    }
};