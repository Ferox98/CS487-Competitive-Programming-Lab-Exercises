class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        bool bought = false;
        int bought_amount = -1;
        for(int i = 0; i < prices.size(); i++) {
            if (!bought && i + 1 < prices.size() && prices[i] < prices[i + 1]) {
                bought = true;
                bought_amount = prices[i];
            }
            else if (bought && (i + 1 == prices.size() || prices[i + 1] < prices[i])) {
                bought = false;
                total_profit += prices[i] - bought_amount;
            }
        }
        return total_profit;                     
    }
};