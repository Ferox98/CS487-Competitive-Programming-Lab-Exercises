class Solution {
public:
    
    int findMinSubarray(vector<int>& cardPoints, int k) {
        int i = 0;
        int j = k - 1;
        if (i > j) return 0;
        int min_sum = 0;
        for (int x = 0; x <= j; x++) {
            min_sum += cardPoints[x];
        }
        int cur_sum = min_sum;
        int min_i = i, min_j = j;
        while (true) {
            cur_sum -= cardPoints[i];
            i++;
            j++;
            if (j >= cardPoints.size()) break;
            cur_sum += cardPoints[j];
            if (cur_sum < min_sum) {
                min_sum = cur_sum;
                min_i = i;
                min_j = j;
            }
        }
        return min_sum;
    }
    
    int dp(vector<int>& cardPoints, vector<vector<int>>& score, int i, int j, int k, int count) {
        if (count == k) return 0;
        if (score[i][j] != INT_MIN) {
            return score[i][j];
        }
        count++;
        score[i][j] = max(cardPoints[i] + dp(cardPoints, score, i + 1, j, k, count), cardPoints[j] + dp(cardPoints, score, i, j - 1, k, count));
        return score[i][j];
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        int total_sum = 0;
        for (auto& card : cardPoints) total_sum += card;
        return total_sum - findMinSubarray(cardPoints, cardPoints.size() - k);
    }
    
};