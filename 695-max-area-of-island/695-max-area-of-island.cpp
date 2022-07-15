
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
    Time: O(m*n)
    Space: O(m*n)
    Tag: DFS
    Difficulty: E 
*/

class Solution {
    int dfs(vector<vector<int>> &grid, int i, int j) {
        grid[i][j] = 0;
        int count = 0;
        if (i > 0 && grid[i - 1][j]) count += dfs(grid, i - 1, j);
        if (i < grid.size() - 1 && grid[i + 1][j]) count += dfs(grid, i + 1, j);
        if (j > 0 && grid[i][j - 1]) count += dfs(grid, i, j - 1);
        if (j < grid[0].size() - 1 && grid[i][j + 1]) count += dfs(grid, i, j + 1);
        return count + 1;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
};