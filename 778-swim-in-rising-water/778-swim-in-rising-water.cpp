/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> distances(n * m, INT_MAX);
        unordered_set<int> visited;
        set<pair<int, int>> q;
        q.insert({grid[0][0], 0});
        distances[0] = grid[0][0];
        while (!q.empty()) {
            int x = q.begin()->second / m;
            int y = q.begin()->second % m;
            int dist = q.begin()->first;
            // cout << x << " " << y << " " << dist << endl;
            vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
            visited.insert(x * m + y);
            if (x * m + y == (m * n) - 1) return distances[(n * m) - 1];
            q.erase(q.begin());
            for (auto move : moves) {
                if (x + move.first >= 0 && x + move.first < n && y + move.second < m && y + move.second >= 0 && visited.find((x + move.first) * m + y + move.second) == visited.end()) {
                    if (max(dist, grid[x + move.first][y + move.second]) < distances[(x + move.first) * m + y + move.second]) {
                        if (distances[(x + move.first) * m + y + move.second] != INT_MAX) {
                            q.erase({distances[(x + move.first) * m + y + move.second],
                                     (x + move.first) * m + y + move.second});
                        }
                        distances[(x + move.first) * m + y + move.second] = max(dist, grid[x + move.first][y + move.second]);
                        q.insert({distances[(x + move.first) * m + y + move.second],
                                  (x + move.first) * m + y + move.second});
                    }
                }
            }
        }
        return (m * n) - 1;
    }
};