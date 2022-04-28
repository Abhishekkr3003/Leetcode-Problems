/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    int res = 0;

    void solve(int row, unordered_set<int> queens[], int n) {
        if (row == n) {
            res++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (queens[0].find(col) == queens[0].end() && queens[1].find(row - col) == queens[1].end() && queens[2].find(row + col) == queens[2].end()) {
                queens[0].insert(col);
                queens[1].insert(row - col);
                queens[2].insert(row + col);
                solve(row + 1, queens, n);
                queens[0].erase(col);
                queens[1].erase(row - col);
                queens[2].erase(row + col);
            }
        }
    }

public:
    int totalNQueens(int n) {
        unordered_set<int> queens[3]; //[vert, main Diag, off Diag]
        solve(0, queens, n);
        return res;
    }
};