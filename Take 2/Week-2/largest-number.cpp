class Solution {
public:
    
    bool isGreater(int num1, int num2) {
    string str1 = to_string(num1), str2 = to_string(num2);
    for (int i = 0; i < min(str1.size(), str2.size()); i++) {
        if (num1 < 0) return false;
        if (num2 < 0) return true;
        int digit_1 = (int) str1[i];
        int digit_2 = (int) str2[i];
        if (digit_1 > digit_2) {
            return true;
        }
        else if (digit_2 > digit_1) {
            return false;
        }
    }
    // numbers are equal upto end of loop
    if (str1.size() == str2.size()) {
        // it doesn't matter, return either
        return true;
    }
    
    string test_str = str1 + str2;
    const int test_1 = stoi(test_str);
    test_str = str2 + str1;
    const int test_2 = stoi(test_str);
    if (test_1 > test_2) {
        return true;
    }
    return false;
}

string largestNumber(vector<int>& nums) {
    string res = "";
    int total = 0, chars = 0;
    while (total < nums.size()) {
        int greatest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0 && isGreater(nums[i], nums[greatest])) {
                greatest = i;               
            }
        }
        res += to_string(nums[greatest]);
        if (nums[greatest] == 0 && total == 0) {
            break;
        }
        nums[greatest] = -1;
        total++;
    }
    return res;
}
};