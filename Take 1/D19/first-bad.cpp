// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    
    long long smallest;
    
    void findFirstBad(long long small, long long large) {
        if (isBadVersion(small)) {
            if (small < smallest) 
                smallest = small;
            return;
        } 
        if (small >= large) return;
        int mid = (long long)((small + large) / 2);
        if (isBadVersion(mid)) {
            if (mid < smallest) smallest = mid;
            // check to its left
            findFirstBad(small, mid - 1);
            return;
        }
        else {
            findFirstBad(mid + 1, large);
            return;
        } 
    }
    int firstBadVersion(int n) {
        smallest = n;    
        findFirstBad(1, (long long)n);
        return smallest;
    }
};