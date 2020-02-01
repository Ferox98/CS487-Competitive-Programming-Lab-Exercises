#include <algorithm>

bool compareEntry(const vector<int>& pair_1, const vector<int>& pair_2) {
        if (pair_1[0] != pair_2[0])
            return pair_1[0] < pair_2[0];
        return pair_1[1] < pair_2[1];
}



class Solution {
public: 
      
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // sort each pair within the vector
        for(int i = 0; i < dominoes.size(); i++) {
            sort(dominoes[i].begin(), dominoes[i].end());
        }
        cout << "sorting finished" << endl;
        // sort the vector based on the first pairs
        sort(dominoes.begin(), dominoes.end(), compareEntry);
        int pair_count = 0;
        cout << "sorting finished" << endl;
        for(int i = 0; i < dominoes.size() - 1; i++) {
            int pair_1 = dominoes[i][0], pair_2 = dominoes[i][1];
            int counter = 0;
            for (i; i < dominoes.size(); i++) {
                if (pair_1 == dominoes[i][0] && pair_2 == dominoes[i][1])
                    counter++;
                else
                    break;
            }
            i--;
            cout << "counter = " << counter << endl;
            pair_count += (counter) * (counter - 1) / 2;
        }
        return pair_count;
    }
};