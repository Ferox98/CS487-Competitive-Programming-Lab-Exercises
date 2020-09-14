bool compare(const vector<int>& pair_1, const vector<int>& pair_2) {
    if (pair_1[0] != pair_2[0])
        return pair_1[0] < pair_2[0];
    return pair_1[1] < pair_2[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort the numbers based on their first and second elements
        sort(pairs.begin(), pairs.end(), compare);
        vector<int> counts(pairs.size(), 1);
        cout << "sorted vector is " << endl;
        for(auto& pair : pairs) cout << "(" << pair[0] << " , " << pair[1] << ") , ";
        cout << endl;
        int max_count = 1;
        for(int i = pairs.size() - 1; i >= 0; i--) {
            // try to append a pair to this element
            for(int j = i + 1; j < pairs.size(); j++) {
                if (pairs[i][1] < pairs[j][0]) 
                    counts[i] = max(counts[i], counts[j] + 1);
                if (counts[i] > max_count)
                    max_count = counts[i];
            }
        }
        return max_count;
    }
};