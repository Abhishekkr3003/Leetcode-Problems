/*
    Time: O(n^3)
    Space: O(n^3)
    Tag: DP (01 Knapsack)
    Difficulty: M
*/

int findMinCost(vector < vector<vector<int>>>& t, int index, int m, int n, vector<vector<int>>& costs) {
    if (index == costs.size()) return 0;
    if (t[index][m][n] != -1) return t[index][m][n];
    int minCost = INT_MAX;
    if (m < costs.size() / 2) {
        minCost = min(minCost, findMinCost(t, index + 1, m + 1, n, costs) + costs[index][0]);
    }
    if (n < costs.size() / 2) {
        minCost = min(minCost, findMinCost(t, index + 1, m, n + 1, costs) + costs[index][1]);
    }
    return t[index][m][n] = minCost;
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector < vector<vector<int>>>t(n + 1, vector<vector<int>>(n + 1, vector<int>(n, -1)));
        return findMinCost(t, 0, 0, 0, costs);
    }
};