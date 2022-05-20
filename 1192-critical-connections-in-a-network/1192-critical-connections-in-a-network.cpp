/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    vector<int> disc, low;
    vector<vector<int>> res;
    vector<bool> visited;
    int time = 0;

    void dfs(int node, int parent, vector<int> graph[]) {
        visited[node] = true;
        time++;
        disc[node] = low[node] = time;
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                dfs(nbr, node, graph);
                low[node] = min(low[node], low[nbr]);
                if (low[nbr] > disc[node]) res.push_back({node, nbr});
            } else if (nbr != parent) {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        vector<int> graph[n];
        for (auto &e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        disc.resize(n, INT_MAX);
        low.resize(n, INT_MAX);
        visited.resize(n, false);
        dfs(0, -1, graph);
        return res;
    }
};