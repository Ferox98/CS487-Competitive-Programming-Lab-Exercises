class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups;
        map<int, bool> in_group;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (in_group[i] == true) continue;
            int group_size = groupSizes[i];
            vector<int> group;
            group.push_back(i);
            in_group[i] = true;
            for (int j = i + 1; j < groupSizes.size(); j++) {
                if (group.size() == group_size) break;
                if (groupSizes[j] == group_size) {
                    group.push_back(j);
                    in_group[j] = true;
                }
                
            }
            groups.push_back(group);
        }
        return groups;
    }
};