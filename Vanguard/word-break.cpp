class Solution {
public:
    
    bool wordBreakMemo(string& s, int start, unordered_set<string>& words, vector<int>& memo) {
        if (start >= s.size()) return true;
        if (memo[start] != -1) return ((bool) memo[start]);
        for (int i = start; i < s.size(); i++) {
            string word = s.substr(start, i - start + 1);
            if (words.find(word) != words.end()) {
                bool res = wordBreakMemo(s, i + 1, words, memo);
                if (i + 1 < memo.size()) memo[i + 1] = (int) res;
                if (res == true) return true;
            }
        }
        memo[start] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return wordBreakMemo(s, 0, words, memo);
    }
};