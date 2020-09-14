vector<int> optimal_move(1000, -1);

class Solution {
public:
        
    bool divisorGame(int N) {
        if (N == 1) return false;
        for(int i = N - 1; i >= 1; i--) if (N % i == 0) {
            if (optimal_move[N - i] == -1) {
                optimal_move[N - i] = divisorGame(N - i);
            }
            if (optimal_move[N - i] == 0) {
                return true;
            }   
        }
        return false;
    }
};