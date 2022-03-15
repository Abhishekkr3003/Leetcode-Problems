#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        unordered_set<string> visited;
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    visited.insert(to_string(i) + " " + to_string(j));
                    q.push({0, {i, j}});
                }
            }
        }
        int maxD = 0;
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            int val = q.front().first;
            pair<int, int> crd = q.front().second;
            q.pop();
            for (pair<int, int> move : moves) {
                if (crd.first + move.first >= 0 && crd.second + move.second >= 0 && crd.second + move.second <= n - 1 && crd.first + move.first <= n - 1) {
                    if (visited.find(to_string(crd.first + move.first) + " " + to_string(crd.second + move.second)) == visited.end() && grid[crd.first + move.first][crd.second + move.second] == 0) {
                        q.push({val + 1, {crd.first + move.first, crd.second + move.second}});
                        maxD = max(maxD, val + 1);
                        visited.insert(to_string(crd.first + move.first) + " " + to_string(crd.second + move.second));
                    }
                }
            }
        }
        return maxD == 0 ? -1 : maxD;
    }
};