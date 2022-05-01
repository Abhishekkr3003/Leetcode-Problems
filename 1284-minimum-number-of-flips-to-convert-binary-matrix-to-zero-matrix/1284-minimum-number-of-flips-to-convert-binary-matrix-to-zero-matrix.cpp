/* 
    Time: O(2^(m*n))
    Space: O(2^(m*n))
    Tag: BFS, Bit Manipulation
    Difficulty: H
*/

class Solution {
public:
    int minFlips(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_set<int> visited;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cur = (cur | (mat[i][j] << i * m + j));
            }
        }
        queue<int> q;
        q.push(cur);
        int nbr;
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int k = 0; k < size; k++) {
                int num = q.front();
                if (num == 0) return dist-1;
                q.pop();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        nbr = num ^ (1 << ((i) * m + j));
                        if (i > 0) {
                            nbr = nbr ^ (1 << ((i - 1) * m + j));
                        }
                        if (j > 0) {
                            nbr = nbr ^ (1 << ((i)*m + j - 1));
                        }
                        if (i < n - 1) {
                            nbr = nbr ^ (1 << ((i + 1) * m + j));
                        }
                        if (j < m - 1) {
                            nbr = nbr ^ (1 << ((i)*m + j + 1));
                        }
                        if (visited.find(nbr) == visited.end()) {
                            visited.insert(nbr);
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        return -1;
    }
};