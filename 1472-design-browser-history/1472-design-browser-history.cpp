class BrowserHistory {
    vector<string>history;
    int curPos;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curPos=0;
    }
    
    void visit(string url) {
        while(curPos<history.size()-1){
            history.pop_back();
        }
        history.push_back(url);
        curPos++;
    }
    
    string back(int steps) {
        curPos=max(0,curPos-steps);
        return history[curPos];
    }
    
    string forward(int steps) {
        curPos=min((int)history.size()-1,curPos+steps);
        return history[curPos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */