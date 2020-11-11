class Solution {
public:
    
    int countSubmat(vector<vector<int>>& mat, int row, int col) {
        int row_size = mat.size();
        int col_size = mat[row].size();
        int bound = col_size;
        int count = 0;
        
        for (int i = row; i < mat.size(); i++) {
            for (int j = col; j < bound; j++) {
                if (mat[i][j]) {
                    count++;            
                }
                else {
                    bound = j;
                }
            }
        }
        return count;
    }
    
    int numSubmat(vector<vector<int>>& mat) {
        int submatrices = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j]) {
                    submatrices += countSubmat(mat, i, j);
                }
            }
        }
        return submatrices;
    }
};