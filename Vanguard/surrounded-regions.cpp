class Solution {
public:
    
    bool isLegal(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) return false;
        return true;
    }
    
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<char>>& res) {
        res[i][j] = 'O';
        vector<vector<int>> neighbors = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};    
        for (auto& neighbor : neighbors) {
            int x = i + neighbor[0];
            int y = j + neighbor[1];
            if (isLegal(x, y, board) && res[x][y] == 'X' && board[x][y] == 'O') {
                dfs(x, y, board, res);
            }
        }
    }
    
    bool isCorner(int i, int j, vector<vector<char>>& board) {
        if (i == 0 || j == 0 || i == board.size() - 1 || j == board[i].size() - 1) return true;
        return false;
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> res(board.size(), vector<char>(board[0].size(), 'X'));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (isCorner(i, j, board) && board[i][j] == 'O' && res[i][j] == 'X') {
                    dfs(i, j, board, res);
                }
            }
        }
        board = res;
    }
};