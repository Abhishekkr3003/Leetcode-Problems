#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int t[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            t[i][0] = 0;
        }
        for (int i = 0; i <= n; i++) {
            t[0][i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    t[i][j] = t[i - 1][j - 1] + 1;
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << t[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return t[m][n];
    }
};