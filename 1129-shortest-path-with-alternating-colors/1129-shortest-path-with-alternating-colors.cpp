/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto edge : redEdges) {
            graph[edge[0]].push_back({edge[1], 0});
        }
        for (auto edge : blueEdges) {
            graph[edge[0]].push_back({edge[1], 1});
        }
        vector<vector<int>> distances(n, vector<int>(2, -1));
        queue<pair<int, int>> q;
        distances[0][0] = distances[0][1] = 0;
        q.push({0, -1});
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int i = 0; i < size; i++) {
                int node = q.front().first;
                int col = q.front().second;
                q.pop();
                for (auto nbr : graph[node]) {
                    if (distances[nbr.first][nbr.second] == -1 && nbr.second != col) {
                        distances[nbr.first][nbr.second] = dist;
                        q.push({nbr.first, nbr.second});
                    }
                }
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (distances[i][0] == -1 && distances[i][1] == -1)
                res[i] = -1;
            else if (distances[i][0] == -1)
                res[i] = distances[i][1];
            else if (distances[i][1] == -1)
                res[i] = distances[i][0];
            else
                res[i] = min(distances[i][0], distances[i][1]);
        }
        return res;
    }
};