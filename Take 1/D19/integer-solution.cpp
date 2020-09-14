class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> sols;
        for (int i = 1; i < 1000; i++) {
            for (int j = 1; j < 1000; j++) {
                int res = customfunction.f(i, j);
                if (res == z) {
                    vector<int> sol = {i, j};
                    sols.push_back(sol);
                    break;
                }
                else if (res > z)
                    break;
            }
        }
        return sols;
    }
};