class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(m * n, vector<bool>(k + 1, false));
        queue<pair<int, int>> q;
        q.push({0, k});
        visited[0][k] = true;
        int size, dist = 0;
        while (!q.empty()) {
            dist++;
            size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first / m;
                int y = q.front().first % m;
                int power = q.front().second;
                if (x == n - 1 && y == m - 1) return dist - 1;
                q.pop();
                if (x > 0) {
                    if (grid[x - 1][y] && power && visited[(x - 1) * m + y][power - 1] == false) {
                        visited[(x - 1) * m + y][power - 1] = 1;
                        q.push({(x - 1) * m + y, power - 1});
                    } else if (grid[x - 1][y] == 0 && visited[(x - 1) * m + y][power] == false) {
                        visited[(x - 1) * m + y][power] = 1;
                        q.push({(x - 1) * m + y, power});
                    }
                }
                if (x < n - 1) {
                    if (grid[x + 1][y] && power && visited[(x + 1) * m + y][power - 1] == false) {
                        visited[(x + 1) * m + y][power - 1] = 1;
                        q.push({(x + 1) * m + y, power - 1});
                    } else if (grid[x + 1][y] == 0 && visited[(x + 1) * m + y][power] == false) {
                        q.push({(x + 1) * m + y, power});
                        visited[(x + 1) * m + y][power] = 1;
                    }
                }
                if (y > 0) {
                    if (grid[x][y - 1] && power && visited[(x)*m + (y - 1)][power - 1] == false) {
                        q.push({(x)*m + (y - 1), power - 1});
                        visited[(x)*m + (y - 1)][power - 1] = 1;
                    } else if (grid[x][y - 1] == 0 && visited[(x)*m + (y - 1)][power] == false) {
                        q.push({(x)*m + (y - 1), power});
                        visited[(x)*m + (y - 1)][power] = 1;
                    }
                }
                if (y < m - 1) {
                    if (grid[x][y + 1] && power && visited[(x)*m + (y + 1)][power - 1] == false) {
                        q.push({(x)*m + (y + 1), power - 1});
                        visited[(x)*m + (y + 1)][power - 1] = 1;
                    } else if (grid[x][y + 1] == 0 && visited[(x)*m + (y + 1)][power] == false) {
                        q.push({(x)*m + (y + 1), power});
                        visited[(x)*m + (y + 1)][power] = 1;
                    }
                }
            }
        }
        return -1;
    }
};