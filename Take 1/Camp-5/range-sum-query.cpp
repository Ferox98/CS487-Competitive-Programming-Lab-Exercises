class NumArray {
public:
    vector<int> numbers;
    NumArray(vector<int>& nums) {
        numbers = nums;
        for(int i = 1; i < numbers.size(); i++)
            numbers[i] += numbers[i - 1];
    }
    
    int sumRange(int i, int j) {
        if(i == 0) {
            return numbers[j];
        }
        return numbers[j] - numbers[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */