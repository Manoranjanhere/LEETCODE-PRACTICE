class MinStack {
public:
        stack<int> ns;
        stack<int> mn;
    MinStack() {
    }
    
    void push(int val) {
        ns.push(val);
        if(!mn.empty())mn.push(min(mn.top(),val));
        else mn.push(val);
    }
    
    void pop() {
        ns.pop();
        mn.pop();
    }
    
    int top() {
        return ns.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */