/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        unordered_set<int> visited;

        vector<int> distances(n * m, INT_MAX);
        set<pair<int, int>> q;
        q.insert({0, 0});
        while (!q.empty()) {
            int pathDist = q.begin()->first;
            int x = q.begin()->second / m;
            int y = q.begin()->second % m;
            visited.insert(x * m + y);
            if (x == n - 1 && y == m - 1) return pathDist;
            q.erase(q.begin());
            if (x > 0 && visited.find((x - 1) * m + y) == visited.end()) {
                if (distances[(x - 1) * m + y] > max(pathDist, abs(heights[x - 1][y] - heights[x][y]))) {
                    if (q.find({distances[(x - 1) * m + y], (x - 1) * m + y}) != q.end())
                        q.erase({distances[(x - 1) * m + y], (x - 1) * m + y});
                    distances[(x - 1) * m + y] = max(pathDist, abs(heights[x - 1][y] - heights[x][y]));
                    q.insert({distances[(x - 1) * m + y], (x - 1) * m + y});
                }
            }
            if (y > 0 && visited.find((x)*m + y - 1) == visited.end()) {
                if (distances[(x)*m + y - 1] > max(pathDist, abs(heights[x][y - 1] - heights[x][y]))) {
                    if (q.find({distances[(x)*m + y - 1], (x)*m + y - 1}) != q.end())
                        q.erase({distances[(x)*m + y - 1], (x)*m + y - 1});
                    distances[(x)*m + y - 1] = max(pathDist, abs(heights[x][y - 1] - heights[x][y]));
                    q.insert({distances[(x)*m + y - 1], (x)*m + y - 1});
                }
            }
            if (x < n - 1 && visited.find((x + 1) * m + y) == visited.end()) {
                if (distances[(x + 1) * m + y] > max(pathDist, abs(heights[x + 1][y] - heights[x][y]))) {
                    if (q.find({distances[(x + 1) * m + y], (x + 1) * m + y}) != q.end())
                        q.erase({distances[(x + 1) * m + y], (x + 1) * m + y});
                    distances[(x + 1) * m + y] = max(pathDist, abs(heights[x + 1][y] - heights[x][y]));
                    q.insert({distances[(x + 1) * m + y], (x + 1) * m + y});
                }
            }
            if (y < m - 1 && visited.find((x)*m + y + 1) == visited.end()) {
                if (distances[(x)*m + y + 1] > max(pathDist, abs(heights[x][y + 1] - heights[x][y]))) {
                    if (q.find({distances[(x)*m + y + 1], (x)*m + y + 1}) != q.end())
                        q.erase({distances[(x)*m + y + 1], (x)*m + y + 1});
                    distances[(x)*m + y + 1] = max(pathDist, abs(heights[x ][y+1] - heights[x][y]));
                    q.insert({distances[(x)*m + y + 1], (x)*m + y + 1});
                }
            }
        }
        return 0;
    }
};