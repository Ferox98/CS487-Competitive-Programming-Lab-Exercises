#include <sstream>

class Solution {
public:   
    int toInt(string str) {
        stringstream ss(str);
        int val;
        ss >> val;
        return val;
    }

    string complexNumberMultiply(string a, string b) {
        char cross_pos_1 = a.find('+'), cross_pos_2 = b.find('+');
        int normal_1 = toInt(a.substr(0, a.find('+')));
        int normal_2 = toInt(b.substr(0, b.find('+')));
        int complex_1 = toInt(a.substr(a.find('+') + 1, a.find('i')));
        int complex_2 = toInt(b.substr(b.find('+') + 1, b.find('i')));
        int normal_product = normal_1 * normal_2 - complex_1 * complex_2;
        int complex_product = complex_1 * normal_2 + complex_2 * normal_1;
        return to_string(normal_product) + "+" + to_string(complex_product) + "i";
    }
};