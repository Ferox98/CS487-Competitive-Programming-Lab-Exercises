#include <vector>
#include <algorithm>

class Solution {
public:
    
    int findLargest(vector<int>& vec, int maximum) {
        int largest = 0;
        for(int i = 97; i < 123; i++) {
            if(vec[i] > vec[largest] && i != maximum) 
                largest = i;            
        }
        return largest;
    }
    string reorganizeString(string S) {
        vector<int> vec(123, 0);
        string res;
        for(auto& c : S)
            vec[(int)(c)]++;
        while(true) {
            int idx_1 = findLargest(vec, -1);
            int idx_2 = findLargest(vec, idx_1);
            cout << idx_1 << " , " << idx_2 << endl;
            if(idx_1 == 0) break;
            res += (char)(idx_1);
            if(idx_2 == 0) break;
            res += (char)(idx_2);
            vec[idx_1]--, vec[idx_2]--;
        }
        if (res.size() < S.size()) return "";
        cout << res << endl;
        return res;
    }
};