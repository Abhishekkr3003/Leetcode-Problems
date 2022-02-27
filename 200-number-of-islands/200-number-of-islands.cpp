#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {

    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;

    void dfs(int i, int j, vector<vector<char>> &grid) {
        // cout << i << " " << j << endl;
        if (grid[i][j]=='1') {
            grid[i][j] = '0';
            for (pair<int, int> move : moves) {
                if ((i + move.first >= 0) && (i + move.first < m) && (j + move.second >= 0) && (j + move.second < n)) {
                    dfs(i + move.first, j + move.second, grid);
                }
            }
        }
        return;
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]=='1') {
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
};