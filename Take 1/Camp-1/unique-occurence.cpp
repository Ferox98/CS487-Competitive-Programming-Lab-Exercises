class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int num = arr[0], count = 0;
        set<int> counts;
        for(int i = 0; i < arr.size(); i++) {
            if (arr[i] == num) {
                count++;
            }    
            else {
                // check if current count exists in the count vector
                if (counts.find(count) != counts.end())
                    return false;
                counts.insert(count);
                num = arr[i];
                count = 1;
            }
        }
        if (counts.find(count) != counts.end())
            return false;
        return true;
    }
};