class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int ans=0;
        unordered_map<int, int> m;
        for (int i = 0; i< nums.size(); i++){
            m[nums[i]]++;
        }
        auto it = m.begin();
        while (it != m.end()) {
            int a = it->second;
            while(a > 0){
                ans += (it->first+1);
                a -= (it->first+1);
            }
            it++;
        }
        return ans;
    }
};