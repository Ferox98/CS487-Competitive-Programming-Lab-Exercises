
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> vec;
    MinStack() {
        
    }
    
    void push(int x) {
        vec.push_back(x);   
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec[vec.size() - 1];
    }
    
    int getMin() {
        return *min_element(vec.begin(), vec.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */