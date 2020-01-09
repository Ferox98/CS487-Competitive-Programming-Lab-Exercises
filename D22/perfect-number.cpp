class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0 || num == 1) return false;
        int sum = 0;
        for(int i = 1; i < num; i++) {
            if (sum > num) return false;
            if (i >= sqrt(num) && sum == 1) return false; 
            if (num % i == 0) sum += i;
            if (i == num / 2) break;
        }
        if (sum == num) return true;
        return false;
    }
};