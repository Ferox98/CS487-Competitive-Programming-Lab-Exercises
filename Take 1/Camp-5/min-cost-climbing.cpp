class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> total_cost = cost;
        for(int i = 2; i < cost.size(); i++) {
            total_cost[i] += min(total_cost[i - 1], total_cost[i - 2]);
        }
        int last_idx = total_cost.size() - 1;
        total_cost.insert(total_cost.end(), min(total_cost[last_idx], total_cost[last_idx - 1]));
        return total_cost[last_idx + 1];
    }
};