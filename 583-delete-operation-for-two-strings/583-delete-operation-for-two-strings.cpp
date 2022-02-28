
/* 
    Time: O(m*n)
    Space: O(m*n)
    Tag: DP (LCS Pattern)
    Difficulty: M
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            t[i][0] = 0;
        }
        for (int i = 0; i <= n; i++) {
            t[0][i] = 0;
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return m + n - 2 * t[m][n];
    }
};