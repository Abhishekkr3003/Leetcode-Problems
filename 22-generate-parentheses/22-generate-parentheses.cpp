class Solution {
    void solve(int n,int openCount,int closedCount,string curString, vector<string>&res){
        if(closedCount==n) {
            res.push_back(curString);
            return;
        }
        if(openCount>closedCount)
            solve(n,openCount,closedCount+1,curString+")",res);
        if(openCount<n)
            solve(n,openCount+1,closedCount,curString+"(",res);
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(n,0,0,"",res);
        return res;
    }
};