class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const auto& person_1, const auto& person_2) {
            if (person_1[0] == person_2[0]) {
                return person_1[1] > person_2[1];
            }
            return person_1[0] < person_2[0];
        });
        vector<vector<int>> res;
        for (int i = people.size() - 1; i >= 0; i--) {
            if (res.size() == 0) res.push_back(people[i]);
            else {
                int front = people[i][1];
                res.insert(res.begin() + front, people[i]);    
            }        
        }
        return res;
    }
};