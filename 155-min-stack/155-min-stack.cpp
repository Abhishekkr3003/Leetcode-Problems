class MinStack {
    stack<long>st;
    long minEle;
    
public:
    MinStack() {
        minEle=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            minEle=val;
            st.push(val);
            return;
        }
        if(val<minEle) {
            st.push(2ll*val-minEle);
            minEle=val;
        }else st.push(val);
        // cout<<st.top()<<endl;
    }
    
    void pop() {
        if(st.top()<minEle){
            minEle=2ll*minEle-st.top();
        }
        st.pop();
        if(st.empty()) {
            minEle=INT_MAX;
        }
    }
    
    int top() {
        if(st.top()<minEle) {
            return minEle;
        }
        return st.top();
    }
    
    int getMin() {
        return minEle;
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