class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> start;
        map<char, int> end;
        for (int i = 0; i < S.size(); i++) {
            if (start[S[i]] == 0 && S[0] != S[i]) {
                start[S[i]] = i;
            }
            end[S[i]] = i;
        }
        vector<pair<int, int>> intervals;
        for(map<char, int>::iterator iter = start.begin(); iter != start.end(); iter++) {
            char c = iter->first;
            int start_pos = iter->second;
            int end_pos = end[c];
            intervals.push_back(pair<int, int>(start_pos, end_pos));
        }
        sort(intervals.begin(), intervals.end(), [](const auto& pair_1, const auto& pair_2) {
            return pair_1.second <= pair_2.second;
        });
        vector<int> partitions;
        int k = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int partition_point = intervals[i].second;
            bool found = false;
            for (int j = i + 1; j < intervals.size(); j++) {
                if (intervals[j].first < partition_point && intervals[j].second > partition_point) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                partitions.push_back(partition_point - k + 1);
                k = partition_point + 1;
            }
        }
        return partitions;
    }
};