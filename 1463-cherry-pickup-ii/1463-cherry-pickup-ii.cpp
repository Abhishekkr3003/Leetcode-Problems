/*
    Time: O(m*n*n)
    Space: O(m*n*n)
    Tag: DP - Matrix
    Difficulty: M
*/

class Solution {
    vector<vector<vector<int>>> t;
    vector<vector<int>> grid;
    int n;
    int m;

    int recur(int level, int i, int j) {
        if (level >= m) return 0;
        if (t[level][i][j] != -1) return t[level][i][j];
        int res = 0;
        if (i + 1 < n && j + 1 < n)
            res = max(res, recur(level + 1, i + 1, j + 1));
        if (i - 1 >= 0 && j + 1 < n && i - 1 != j + 1)
            res = max(res, recur(level + 1, i - 1, j + 1));
        if (i - 1 >= 0 && j - 1 >= 0)
            res = max(res, recur(level + 1, i - 1, j - 1));
        if (i + 1 < n && j - 1 >= 0 && i + 1 != j - 1)
            res = max(res, recur(level + 1, i + 1, j - 1));
        if (j + 1 < n && j + 1 != i) res = max(res, recur(level + 1, i, j + 1));
        if (j - 1 >= 0 && j - 1 != i)
            res = max(res, recur(level + 1, i, j - 1));
        if (i - 1 >= 0 && i - 1 != j)
            res = max(res, recur(level + 1, i - 1, j));
        if (i + 1 < n && i + 1 != j) res = max(res, recur(level + 1, i + 1, j));
        res = max(res, recur(level + 1, i, j));
        t[level][i][j] = res + grid[level][i] + grid[level][j];

        // cout << level << " " << i << " "
        //      << " " << j << " " << t[level][i][j] << endl;

        return t[level][i][j];
    }

   public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        t.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));
        this->grid = grid;
        return recur(0, 0, n - 1);
    }
};