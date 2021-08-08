class Solution {
public:
    
    struct TrieNode {
        vector<TrieNode*> children;
        bool is_end;
        
        TrieNode() {
            is_end = false;
            for (int i = 0; i < 26; i++) {
                children.push_back(NULL);
            }
        }
    };
    
    void insert(TrieNode* root, string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->is_end = true;
    }
    
    bool isLegal(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>> visited, int i, int j, TrieNode* node, vector<vector<int>>& neighbors, map<string, bool>& found, string cur_str) {
        cout << cur_str << endl;
        visited[i][j] = true;
        if (node->is_end) {
            found[cur_str] = true;
        }
        
        for (int k = 0; k < neighbors.size(); k++) {
            int x = i + neighbors[k][0];
            int y = j + neighbors[k][1];
            if (isLegal(board, x, y) && !visited[x][y]) {
                char c = board[x][y];
                int idx = c - 'a';
                if (node->children[idx]) {
                    visited[x][y] = true;
                    cur_str += c;
                    dfs(board, visited, x, y, node->children[idx], neighbors, found, cur_str);
                    cur_str.pop_back();
                }
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& word : words) {
            insert(root, word);
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<vector<int>> neighbors = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        map<string, bool> found;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                char c = board[i][j];
                int idx = c - 'a';
                if (root->children[idx]) {
                    string s;
                    s += c;
                    dfs(board, visited, i, j, root->children[idx], neighbors, found, s);
                    if (found.size() == words.size()) break;
                }
            }
        }
        vector<string> res;
        for (map<string, bool>::iterator it = found.begin(); it != found.end(); it++) {
            res.push_back(it->first);
        }
        return res;
    }
};