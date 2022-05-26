/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    int solve(vector<vector<int>> &grid, vector<bool> &visited, int i, int j, int maxCol, int maxRow) {
        visited[i * maxCol + j] = true;
        int res = 0;
        if (i > 0 && grid[i-1][j] && visited[(i - 1) * maxCol + j] == false) res = max(res, solve(grid, visited, i - 1, j, maxCol, maxRow));
        if (j > 0 && grid[i][j-1] && visited[(i)*maxCol + j - 1] == false) res = max(res, solve(grid, visited, i, j - 1, maxCol, maxRow));
        if (i < maxRow - 1 && grid[i+1][j] && visited[(i + 1) * maxCol + j] == false) res = max(res, solve(grid, visited, i + 1, j, maxCol, maxRow));
        if (j < maxCol - 1 && grid[i][j+1] && visited[(i)*maxCol + j + 1] == false) res = max(res, solve(grid, visited, i, j + 1, maxCol, maxRow));
        visited[i * maxCol + j] = false;
        return res+grid[i][j];
    }

public:
    int getMaximumGold(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<bool> visited(m * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, solve(grid, visited, i, j, m, n));
            }
        }
        return res;
    }
};