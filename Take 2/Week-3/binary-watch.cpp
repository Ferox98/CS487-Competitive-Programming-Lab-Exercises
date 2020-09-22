class Solution {
public:
    
    unsigned int countSetBits(unsigned int n) 
    { 
        unsigned int count = 0; 
        while (n) { 
            count += n & 1; 
            n >>= 1; 
        } 
        return count; 
    } 
    
    vector<string> readBinaryWatch(int num) {
        vector<string> results;
        for (int i = 0; i < 12; i++) {
            int hour_setbits = countSetBits(i);
            for (int j = 0; j < 60; j++) {
                int min_setbits = countSetBits(j);
                if (hour_setbits + min_setbits == num) {
                    string res = to_string(i) + ":";
                    string min = to_string(j);
                    if (min.size() == 1) min = "0" + min;
                    res += min;
                    results.push_back(res);
                }
            }
        }
        return results;
    }
};