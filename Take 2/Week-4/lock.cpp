class Solution {
public:
    
    map<string, bool> discovered;
    vector<vector<int>> neighbors;
    map<string, int> parent_length;
    
    int isReachable(string target, map<string, bool>& is_deadend) {
        string start = "0000";
        
        if (is_deadend[start]) {
            return -1;
        }
        queue<pair<string, int>> q;
        q.push(pair<string, int>(start, 0));
        int shortest_path = INT_MAX;
        discovered[start] = true;
        while(!q.empty()) {
            pair<string, int> node = q.front();
            q.pop();
            string str = node.first;
            int path_length = node.second;
            if (str == target) {
                shortest_path = min(shortest_path, path_length);
                break;
            }
            for (int i = 0; i < 4; i++) {
                string temp = str;
                int digit = str[i] - '0';
                digit--;
                if (digit == -1) digit = 9;
                int new_path_length = path_length + 1;
                
                temp[i] = digit + '0';
                if (!discovered[temp] && !is_deadend[temp]) {
                    q.push(pair<string, int>(temp, new_path_length));  
                    discovered[temp] = true;
                }
                
                digit = str[i] - '0';
                digit++;
                if (digit == 10) digit = 0;
                temp[i] = digit + '0';
                
                if (!discovered[temp] && !is_deadend[temp]) {
                    q.push(pair<string, int>(temp, new_path_length));
                    discovered[temp] = true;
                }
            }
        }
        if (shortest_path == INT_MAX) return -1;
        return shortest_path;
    }
    
    int openLock(vector<string>& deadends, string target) {
        map<string, bool> is_deadend;
        for (auto& str : deadends) {
            is_deadend[str] = true;
        }
        int res = isReachable(target, is_deadend);
        return res;
    }
};