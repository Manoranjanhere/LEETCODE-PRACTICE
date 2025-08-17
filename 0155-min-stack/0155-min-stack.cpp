class MinStack {
public:
    vector<int> vec;
    stack<int> st;
    MinStack() {
        
    }
    void push(int val) {
        st.push(val);
        if(vec.size()==0||vec.back()>val)vec.push_back(val);
        else
        {
            vec.push_back(vec.back());
        }
    }
    
    void pop() {
        st.pop();
        vec.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return vec.back();
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