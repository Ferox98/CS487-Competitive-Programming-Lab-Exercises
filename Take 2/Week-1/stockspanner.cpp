class StockSpanner {
public:
    stack<pair<int, int>> prices;
    StockSpanner() {
        prices = stack<pair<int, int>>();
    }
    
    int next(int price) {
        int w = 1;
        while (!prices.empty() && prices.top().first <= price) {
            pair<int, int> stock = prices.top();
            prices.pop();
            w += stock.second;
        }
        prices.push(pair<int, int>(price, w));
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */