/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &color) {
        bool res = true;
        for (int nbr : graph[node]) {
            if (color[nbr] == 0) {
                color[nbr] = 3 - color[node];
                res = res && dfs(nbr, graph, color);
            } else if (color[nbr] == color[node])
                return false;
        }
        return res;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto v : dislikes) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<int> color(n + 1, 0);
        bool res = true;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                res = res && dfs(i, graph, color);
                if (!res) return false;
            }
        }
        return true;
    }
};