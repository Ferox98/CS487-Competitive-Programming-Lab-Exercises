class Solution {
public:
    
    bool find(vector<vector<int>> matrix, int low, int high, int target) {
        if (low > high) return false;
        int mid = (low + high) / 2;
        int last_idx = matrix[mid].size() - 1;
        if (last_idx == -1) {
         //   cout << "returning false" << endl;
            return false;
        }
        if (matrix[mid][0] <= target) {
            if (matrix[mid][last_idx] >= target) {
                // if target is in matrix, it's here
                for (int i = 0; i < matrix[0].size(); i++) {
                    if (matrix[mid][i] == target) {
                        return true;
                    }
                }
                return false;    
            }
            // search bottom rows
            return find(matrix, mid + 1, high, target);
        }
        // search upper rows
        return find(matrix, low, mid - 1, target);        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return find(matrix, 0, matrix.size() - 1, target);
    }
};