class BrowserHistory {
    vector<string>history;
    int curPos;
    int historySize;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curPos=0;
        historySize=1;
    }
    
    void visit(string url) {
        if(curPos==history.size()-1) {
            history.push_back(url);
            historySize=history.size();
            curPos++;
        }
        else {
            history[++curPos]=url;
            historySize=curPos+1;
        }
    }
    
    string back(int steps) {
        curPos=max(0,curPos-steps);
        return history[curPos];
    }
    
    string forward(int steps) {
        curPos=min((int)historySize-1,curPos+steps);
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