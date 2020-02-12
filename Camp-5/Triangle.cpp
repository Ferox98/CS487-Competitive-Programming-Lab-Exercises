class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> sums = triangle;
        if(sums.size() == 0) return 0;
        if(sums.size() == 1) return sums[0][0];
        
        for(int i = sums.size() - 2; i >= 0; i--) {
            for(int j = 0; j < sums[i].size(); j++) {
                sums[i][j] += min(sums[i + 1][j], sums[i + 1][j + 1]);
            }   
        }
        return sums[0][0];
    }
};
