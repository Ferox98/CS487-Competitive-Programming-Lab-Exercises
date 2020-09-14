class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stack_1, stack_2;
    
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack_1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!stack_2.empty()) {
            int elem = stack_2.top();
            stack_2.pop();
            return elem;
        }
        while(!stack_1.empty()) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }
        return pop();
    }
    
    /** Get the front element. */
    int peek() {
        if (!stack_2.empty()) {
            return stack_2.top();
        }
        while(!stack_1.empty()) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }
        return peek();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (stack_1.empty() && stack_2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */