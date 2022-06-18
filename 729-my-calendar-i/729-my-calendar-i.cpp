class MyCalendar {
    set<pair<int,int>>st;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        if(st.empty()) {
            st.insert({start,end});
            return true;
        }
        
        auto it=st.lower_bound({end,0});
        if(it==st.begin()){
            st.insert({start,end});
            return true;
        }
        if(prev(it)->second<=start){
            st.insert({start,end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */