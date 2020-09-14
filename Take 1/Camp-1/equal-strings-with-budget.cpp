class Solution {
public:               
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> costs;
        cout << "costs = " << endl;
        for (int i = 0; i < s.size(); i++) {
            int cost = abs((int)s[i] - (int)t[i]);
            costs.push_back(cost);
            cout << cost << " , ";
        }
        int i = 0, j = 0, count = 0, max_count = 0, sum = 0;
        while (i < costs.size() && j < costs.size()) {
            sum += costs[j];
            if (sum <= maxCost) {
                count++;
            }
            cout << j << " , " << sum << " , " << count << endl;
            if (count > max_count) {
                max_count = count;
            }
            else if (sum > maxCost) {
                sum -= costs[i];
                i++;  
            }
            j++;
        }
        return max_count;
    }

};