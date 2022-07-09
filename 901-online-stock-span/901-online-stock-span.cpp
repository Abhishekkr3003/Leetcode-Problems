class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int resCount=0;
        while(!st.empty() && st.top().first<=price){
            resCount+=st.top().second;
            st.pop();
        }
        st.push({price,resCount+1});
        return resCount+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */