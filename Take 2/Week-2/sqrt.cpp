class Solution {
public:
    
    int sqrt(int x, int low, int high) {
        if (low >= high) return low;
        int mid = (low + high) / 2;
        //cout << low << " , " << mid << " , " << high << endl;
        if ((long long) mid * mid == (long long) x) return mid;
        if ((long long) mid * mid < (long long) x) {
            if ((mid + 1) * (mid + 1) > x) {
                return mid;    
            }
            //cout << 1 << endl;
            return sqrt(x, mid + 1, high);
        }
        return sqrt(x, low, mid - 1);
    }
    
    int mySqrt(int x) {
        return sqrt(x, 0, x);
    }
};