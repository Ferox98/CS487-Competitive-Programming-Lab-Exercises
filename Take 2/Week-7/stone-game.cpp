class Solution {
public:
    
    int dp(int i, int j, vector<int>& piles, vector<vector<vector<int>>>& score, int turn) {
        if (i > j) return 0;
        if (score[i][j][turn] != INT_MIN) {
            return score[i][j][turn];
        }
        int next = abs(turn - 1);
        if (turn == 1) {
            // lee's turn
            score[i][j][turn] = min(-piles[i] + dp(i + 1, j, piles, score, next), -piles[j] + dp(i, j - 1, piles, score, next));
        }
        else {
            // alex's turn
            score[i][j][turn] = max(piles[i] + dp(i + 1, j, piles, score, next), piles[j] + dp(i, j - 1, piles, score, next));
        }
        return score[i][j][turn];
    }
    
    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>> score(piles.size(), vector<vector<int>>(piles.size(), vector<int>(2)));
        for (int i = 0; i < piles.size(); i++) {
            for (int j = 0; j < piles.size(); j++) {
                for (int k = 0; k <= 1; k++) {
                    score[i][j][k] = INT_MIN;
                }
            }
        }
        
        int final_score = dp(0, piles.size() - 1, piles, score, 0);
        cout << final_score << endl;
        if (final_score > 0) return true;
        return false;
    }
};