class Solution {
    vector<string>res;
    
    void solve(int &n, int &openCount, int &closeCount, string &cur){
        if(openCount==n && closeCount==n){
            res.push_back(cur);
            return;
        }
        if(openCount<n){
            cur+='(';
            openCount++;
            solve(n,openCount,closeCount,cur);
            cur.pop_back();
            openCount--;
        }
        if(closeCount<openCount){
            cur+=')';
            closeCount++;
            solve(n,openCount,closeCount,cur);
            cur.pop_back();
            closeCount--;
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        string cur="";
        int openCount=0, closeCount=0;
        solve(n,openCount,closeCount,cur);
        return res;
    }
};