#include <algorithm>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        for(auto& elem : nums1) {
            if(find(nums2.begin(), nums2.end(), elem) != nums2.end()) {
                if(find(intersection.begin(), intersection.end(), elem) == intersection.end())
                    intersection.push_back(elem);
            }
        }
        return intersection;
    }
};