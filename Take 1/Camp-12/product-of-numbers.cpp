class ProductOfNumbers {
public:
    vector<int> list;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        list.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1, counter = 0;
        for(int i = list.size() - 1; i >= 0; i--) {
            if (counter == k) break;
            product *= list[i];
            counter++;
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */