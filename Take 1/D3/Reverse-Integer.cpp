class Solution {
public:
    int reverse(int x) {
        int quotient, rem, sum = 0;
        while(true) {
            quotient = (int) (x / 10);
            rem = x % 10;
            int res = 0;
            if (x >= 0)
                sum += rem * pow(10, (to_string(x).size() - 1));
            else
                sum += rem * pow(10, (to_string(x).size() - 2));
            if(sum == INT_MIN || sum == INT_MAX)
                return 0;
            x = quotient;
            if(x == 0)
                break;
        }
        return sum;
    }
};