class Solution {
public:
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& discovered, vector<int>& click) {
        int i = click[0], j = click[1];
        vector<vector<int>> neighbors = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        discovered[i][j] = true;
        if(board[i][j] == 'M') {
            board[i][j] = 'X';
            return;
        }
        else if (board[i][j] == 'E') {
            // are there any mines adjacent to it?
            int mine_count = 0;
            for(int k = 0; k < neighbors.size(); k++) {
                int new_i = i + neighbors[k][0];
                int new_j = j + neighbors[k][1];
                if (new_i < board.size() && new_j < board[0].size() && 
                   board[new_i][new_j] == 'M') {
                   mine_count++;
                }
            }
            if(mine_count == 0) { 
                board[i][j] = 'B';
                for(int k = 0; k < neighbors.size(); k++) {
                   int new_i = i + neighbors[k][0];
                   int new_j = j + neighbors[k][1];
                    if (new_i < board.size() && new_j < board[0].size() &&
                       !discovered[new_i][new_j] && board[new_i][new_j] == 'E') {
                        // do recursive calls if it's an E
                        vector<int> new_click = {new_i, new_j};
                        dfs(board, discovered, new_click);    
                    }
                }
            }
        
            else
                board[i][j] = mine_count + '0';
        } 
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<bool>> discovered(board.size(), vector<bool>(board[0].size(), false));
        dfs(board, discovered, click);
        return board;
    }
};