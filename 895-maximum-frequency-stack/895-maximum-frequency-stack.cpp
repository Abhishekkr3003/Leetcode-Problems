/* 
    Time: O(n)
    Space: O(n)
    Tag: Stack (Make stack for each freq)
    Difficulty: M
*/

class FreqStack {
    int maxFreq;
    unordered_map<int,int>mp;
    unordered_map<int,stack<int>>stacks;
public:
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        mp[val]++;
        stacks[mp[val]].push(val);
        maxFreq=max(maxFreq,mp[val]);
    }
    
    int pop() {
        int res=stacks[maxFreq].top();
        stacks[maxFreq].pop();
        if(stacks[maxFreq].empty()) maxFreq--;
        mp[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */