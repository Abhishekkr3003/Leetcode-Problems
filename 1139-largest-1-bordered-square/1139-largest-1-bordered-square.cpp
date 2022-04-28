/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> horizSum(n + 1, vector<int>(m + 1)), vertSum(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                horizSum[i][j] = horizSum[i][j - 1] + grid[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                vertSum[j][i] = vertSum[j - 1][i] + grid[j - 1][i - 1];
            }
        }
        // for(auto v:vertSum) {
        //     for(int num:v) cout<<num<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(auto v:horizSum) {
        //     for(int num:v) cout<<num<<" ";
        //     cout<<endl;
        // }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int sideLen = 0; sideLen <= min(i, j); sideLen++) {
                    if ((vertSum[i + 1][j + 1] - vertSum[i - sideLen][j + 1] == sideLen + 1) && horizSum[i + 1][j + 1] - horizSum[i + 1][j - sideLen] == sideLen + 1 && horizSum[i - sideLen+1][j + 1] - horizSum[i - sideLen+1][j - sideLen] == sideLen + 1 && vertSum[i + 1][j - sideLen+1] - vertSum[i - sideLen][j - sideLen+1] == sideLen + 1) res = max(res, sideLen + 1);
                }
            }
        }
        return res * res;
    }
};