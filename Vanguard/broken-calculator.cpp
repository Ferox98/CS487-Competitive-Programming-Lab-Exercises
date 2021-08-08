class Solution {
public:
    
    int brokenCalc(int startValue, int target) {
        if (startValue > target) return (startValue - target);
        int num_steps = 0;
        while (target > startValue) {
            if (target % 2 != 0) {
                target++;
            }
            else target /= 2;
            num_steps++;
        }
        return (num_steps + (startValue - target));
    }
};