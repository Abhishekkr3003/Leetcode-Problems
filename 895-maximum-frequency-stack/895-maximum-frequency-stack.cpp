class FreqStack {
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>stacks;
    int curMax;
public:
    FreqStack() {
        curMax=0;
    }
    
    void push(int val) {
        if(freq.find(val)==freq.end()){
            freq[val]=1;
            curMax=max(curMax,1);
            stacks[1].push(val);
            return;
        }
        int oldFreq=freq[val];
        freq[val]=oldFreq+1;
        stacks[oldFreq+1].push(val);
        curMax=max(curMax,oldFreq+1);
    }
    
    int pop() {
        int num=stacks[curMax].top();
        stacks[curMax].pop();
        freq[num]--;
        if(stacks[curMax].empty()) curMax--;
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */