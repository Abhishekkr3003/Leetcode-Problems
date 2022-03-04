/* 
    Time: O(n*n)
    Space: O(n*n)
    Tag: Matrix, DP (Matrix)
    Difficulty: M
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101, vector<double>(101,0));
        if (poured >= 1) t[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if(t[i][j]>1){
                    t[i+1][j]+=(t[i][j]-1)/2;
                    t[i + 1][j + 1] += (t[i][j] - 1) / 2;
                }
            }
        }
        return t[query_row][query_glass]>1?1:t[query_row][query_glass];
    }
};