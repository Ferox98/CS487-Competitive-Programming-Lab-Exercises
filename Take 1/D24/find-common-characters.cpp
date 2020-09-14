class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        map<char, int> characters;
        vector<map<char, int>> mapper;
        for(auto& str : A) {
            map<char, int> counts;
            for(auto& c : str) {
                characters[c]++;
                counts[c]++;
            }
            mapper.push_back(counts);
        }
        vector<string> res;
        for(pair<const char, int>& char_maps : characters) {
            char c = char_maps.first;
            bool not_found = false;
            int cur_count = -1;
            for(auto& map : mapper) {
                if (map[c] == 0) {
                    not_found = true;
                    break;
                }
                if (cur_count == -1) cur_count = map[c];
                else cur_count = min(cur_count, map[c]);
            }
            if (not_found) continue;
            for(int i = 0; i < cur_count; i++) res.push_back(string(1, c));
        }
        return res;
    }
};