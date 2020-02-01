class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.size() == 0) return 0;
        sort(tokens.begin(), tokens.end());
        int points = 0;
        int min_pointer = 0, max_pointer = tokens.size() - 1;
        while(P >= tokens[min_pointer] && min_pointer <= max_pointer) {
            while (min_pointer < tokens.size() && P >= tokens[min_pointer]) {
                cout << "eating " << tokens[min_pointer] << endl;
                P -= tokens[min_pointer];
                points++;
                min_pointer++;
            }
            if (min_pointer >= max_pointer) break;
            cout << min_pointer << " , " << max_pointer << endl;
            while (max_pointer > 0 && P < tokens[min_pointer] && points > 0) {
                cout << "saccing " << tokens[max_pointer] << endl;
                // sac the point for a bigger token
                points--;
                P += tokens[max_pointer];
                max_pointer--;
            }
        }
        return points;
    }
};