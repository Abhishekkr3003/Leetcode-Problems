class MedianFinder {
    priority_queue<int>dec;
    priority_queue<int, vector<int>, greater<int>>inc;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(dec.size()==inc.size()){
            if(dec.empty()){
                dec.push(num);
                return;
            }
            if(inc.top()<num){
                dec.push(inc.top());
                inc.pop();
                inc.push(num);
            }else{
                dec.push(num);
            }
        }else{
            if(dec.top()>num){
                inc.push(dec.top());
                dec.pop();
                dec.push(num);
            }else{
                inc.push(num);
            }
        }
    }
    
    double findMedian() {
        // cout<<"here2";
        if(inc.size()==dec.size()) return (inc.top()+dec.top())/2.0;
        return dec.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */