class Solution {
    bool isSafe(vector<pair<int, int>>marked, int x, int y){
        for(pair<int, int> p: marked){
            if(p.first==x || p.second==y || (p.first+p.second)==x+y || p.second-p.first==y-x){
                return false;
            }
        }
        return true;
    }
    void solveNQueensUtil(int n,  vector<string>&board, vector<pair<int, int>>marked, vector<vector<string>>&res, int row){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){   
            if(isSafe(marked, row, i)){
                marked.push_back({row, i});
                board[row][i]='Q';
                solveNQueensUtil(n, board, marked, res, row+1);
                marked.pop_back();
                board[row][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int, int>>marked;
        string line=".";
        for(int i=1;i<n;i++){
            line+=".";
        }
        vector<string>board(n,line);
        vector<vector<string>>res;
        solveNQueensUtil(n, board, marked, res, 0);
        return res;
    }
};