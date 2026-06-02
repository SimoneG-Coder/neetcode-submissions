class MinStack {
public:
//LOGIC: maintain a minstack where each element from the original stack has a corresponding minimum associated with it.
//the minimum is the min(minstack.top(), value) => the minimum so far. The minstack is such the the minimum value will be on top.
//if pop from the main stack, also pop form the corresponding minstack and do the same with push.
    MinStack() {      
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || minSt.top()>val) minSt.push(val);
        else minSt.push(minSt.top());
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
private:
    stack<int> st;
    stack<int> minSt;
};
