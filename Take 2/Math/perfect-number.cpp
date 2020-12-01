class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num == 1) return false;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                int divisor = num / i;
                if (divisor != i && divisor != num) sum += divisor;
            }
        }
        return (sum == num);
    }
};