class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> pos(1000);
        for(int i = 0; i < pushed.size(); i++) {
            pos[pushed[i]] = i;
        }
        int max_popped = 0;
        for(int i = 0; i < popped.size(); i++) {
            if (pos[popped[i]] > max_popped) max_popped = pos[popped[i]];
            for (int j = i + 1; j < popped.size(); j++) {
                if (pos[popped[j]] < max_popped && pos[popped[j]] > pos[popped[i]])
                    return false;
            }
        }
        return true;
    }
};