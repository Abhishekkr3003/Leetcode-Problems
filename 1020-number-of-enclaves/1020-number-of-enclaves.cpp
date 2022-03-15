#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    bool add;

    int dfs(int i, int j, vector<vector<int>> &grid) {
        int compSize = 0;
        // cout << i << " " << j << endl;
        if (grid[i][j]) {
            grid[i][j] = 0;
            for (pair<int, int> move : moves) {
                if ((i + move.first >= 0) && (i + move.first < m) && (j + move.second >= 0) && (j + move.second < n)) {
                    compSize += dfs(i + move.first, j + move.second, grid);
                } else {
                    // cout << "here\n";
                    add = false;
                }
            }
            return compSize + 1;
        }
        return 0;
    }

public:
    int numEnclaves(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        int res=0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    add = true;
                    count = dfs(i, j, grid);
                    // cout << "count: " << count << endl;
                    if (add)
                        res += count;
                }
            }
        }
        return res;
    }
};