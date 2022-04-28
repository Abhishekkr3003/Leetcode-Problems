/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    int res = 0;
    unordered_set<int> queens[3]; //[vert, main Diag, off Diag]
    int n;

    void solve(int row) {
        if (row == n) {
            res++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (queens[0].find(col) == queens[0].end() && queens[1].find(row - col) == queens[1].end() && queens[2].find(row + col) == queens[2].end()) {
                queens[0].insert(col);
                queens[1].insert(row - col);
                queens[2].insert(row + col);
                solve(row + 1);
                queens[0].erase(col);
                queens[1].erase(row - col);
                queens[2].erase(row + col);
            }
        }
    }

public:
    int totalNQueens(int n) {
        this->n=n;
        solve(0);
        return res;
    }
};