#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;

    void dfs(int i, int j, queue<pair<int, int>> &q, vector<vector<int>> &grid) {
        for (pair<int, int> move : moves) {
            if (i + move.first >= 0 && i + move.first < m && j + move.second >= 0 && j + move.second < n) {
                if (grid[i + move.first][j + move.second] == 1) {
                    q.push({i + move.first, j + move.second});
                    grid[i + move.first][j + move.second] = -1;
                    dfs(i + move.first, j + move.second, q, grid);
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        // for (auto v : grid) {
        //     for (int num : v) {
        //         cout << num << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << endl;
        bool flag = false;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    grid[i][j] = -1;
                    dfs(i, j, q, grid);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        // for (auto v : grid) {
        //     for (int num : v) {
        //         cout << num << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << endl;
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> crd = q.front();
                q.pop();
                for (pair<int, int> move : moves) {
                    if (crd.first + move.first >= 0 && crd.first + move.first < m && crd.second + move.second >= 0 && crd.second + move.second < n) {
                        if (grid[crd.first + move.first][crd.second + move.second] == 0) {
                            q.push({crd.first + move.first, crd.second + move.second});
                            grid[crd.first + move.first][crd.second + move.second] = -1;
                        } else if (grid[crd.first + move.first][crd.second + move.second] == 1) {
                            return res;
                        }
                    }
                }
                // for (auto v : grid) {
                //     for (int num : v) {
                //         cout << num << " ";
                //     }
                //     cout << "\n";
                // }
            }
            res++;
        }
        return 1;
    }
};