class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<bool>& discovered, int v) {
        // explore all friends of v
        discovered[v] = true;
        for(int i = 0; i < M[v].size(); i++) {
            if (i != v && M[v][i] == 1 && !discovered[i]) {
                dfs(M, discovered, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> discovered(M.size(), false);
        int friends = 0;
        for(int i = 0; i < M.size(); i++) {
            bool friends_added = false;
            for(int j = 0; j < M[i].size(); j++) {
                if (i != j && M[i][j] == 1 && !discovered[j]) {
                    discovered[i] = true;
                    dfs(M, discovered, j);
                    if(!friends_added) friends++;
                    friends_added = true;
                }
            }
            if (!discovered[i]) {
                discovered[i] = true;
                friends++;
            }
        }
        return friends;
    }
};