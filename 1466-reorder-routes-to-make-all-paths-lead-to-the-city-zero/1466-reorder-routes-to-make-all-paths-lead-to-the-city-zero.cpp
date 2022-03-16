/* 
    Time: O(n+e)
    Space: O(n+e)
    Tag: DFS
    Difficulty: M
*/

class Solution {

    int dfs(vector<vector<int>> &undir, vector<unordered_set<int>> &dir, int node, vector<bool> &visited) {
        int rev = 0;
        for (int nbr : undir[node]) {
            if (!visited[nbr]) {
                if (dir[node].find(nbr) != dir[node].end()) rev++;
                visited[nbr] = true;
                rev += dfs(undir, dir, nbr, visited);
            }
        }
        return rev;
    }

public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<int>> undir(n);
        vector<unordered_set<int>> dir(n);
        vector<bool> visited(n, false);
        for (auto edge : connections) {
            dir[edge[0]].insert(edge[1]);
            undir[edge[0]].push_back(edge[1]);
            undir[edge[1]].push_back(edge[0]);
        }
        visited[0] = true;
        return dfs(undir, dir, 0, visited);
    }
};