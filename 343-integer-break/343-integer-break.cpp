
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
    Time: O(n^2)
    Space: O(n^2)
    Tag: DP - Unbounded Knapsack Pattern
    Difficulty: M
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> t(n, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            t[i][0] = 1;
            t[0][i] = 1;
        }
        t[0][n] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j >= i) {
                    t[i][j] = max(t[i][j - i] * i, t[i - 1][j]);
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n - 1][n];
    }
};