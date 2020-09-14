class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        set<int> unprocessed;
        set<int> unique_results;
        int prev_inserted = 1;
        for (int i = 0; i < A.size(); i++) {
            if (i == 0) {
                unique_results.insert(A[i]);
                unprocessed.insert(A[i]);
                continue;
            }
            set<int> unprocessed_new;
            unprocessed_new.insert(A[i]);
            for (auto& j : unprocessed) unprocessed_new.insert(A[i] | j);
            unprocessed = unprocessed_new;
            for (auto& j : unprocessed) unique_results.insert(j);
        }
        return unique_results.size();
    }
};