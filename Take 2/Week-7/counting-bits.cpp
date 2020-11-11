class Solution {
public:
    
    int getBit(int num, int i) {
        // shift 1 i positions to the left
        // perform and AND with num and check if it's one
        return ((num & (1 << i)) != 0);
    }
    
    vector<int> countBits(int num) {
        vector <int> res = {0};
        for (int i = 1; i <= num; i++) {
            int count = 0;
            for (int j = 0; j < 32; j++) {
                int bit = getBit(i, j);
                if (bit == 1) count++;
            }
            res.push_back(count);
        }
        return res;
    }
};