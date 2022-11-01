/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> res(m);
        int col;

        for (int i = 0; i < m; i++) {
            col = i;
            int j = 0;
            for (j = 0; j < n; j++) {
                if (grid[j][col] == 1) {
                    if (col == m - 1 || grid[j][col + 1] == -1) {
                        res[i] = -1;
                        break;
                    }
                    col++;
                } else {
                    if (col == 0 || grid[j][col - 1] == 1) {
                        res[i] = -1;
                        break;
                    }
                    col--;
                }
            }
            if (j == n) res[i] = col;
        }
        return res;
    }
};