#include <map>

class Solution {
public:
    map<int, int> dict;    
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        map<int, int>::const_iterator iter = dict.find(n);
        if (iter != dict.end())
            return dict[n];
        int res = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        dict[n] = res;
        return res;
    }
};