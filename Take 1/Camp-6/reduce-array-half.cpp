class Solution {
public:
    int minSetSize(vector<int>& arr) { 
        map<int, int> counts;
        for(int i = 0; i < arr.size(); i++) {
            counts[arr[i]]++;
        }
        std::vector<std::pair<int, int>> pairs;
        for (auto itr = counts.begin(); itr != counts.end(); ++itr)
            pairs.push_back(*itr);

        sort(pairs.begin(), pairs.end(), [=](std::pair<int, int>& a, std::pair<int, int>& b)
        {
            return a.second < b.second;
        }
        );
        int removed = 0, removed_count = 0;
        for(int i = pairs.size() - 1; i >= 0; i--) {
            removed += pairs[i].second;
            removed_count++;
            if (arr.size() - removed <= arr.size() / 2)
                return removed_count;
        }
        return removed_count;
    }
};