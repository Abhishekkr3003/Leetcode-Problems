typedef long long ll;

/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    long long maxPoints(vector<vector<int>> &points) {
        ll res = 0;
        int n = points.size();
        int m = points[0].size();
        vector<vector<ll>> t(n, vector<ll>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i][j] = points[i][j];
            }
        }

        vector<ll> maxFromLeft(m), maxFromRight(m);
        for (int i = 1; i < n; i++) {
            maxFromRight[m - 1] = t[i - 1][m - 1];
            maxFromLeft[0] = t[i - 1][0];
            ll maxRightIndex = m - 1, maxLeftIndex = 0;
            for (int j = m - 2; j >= 0; j--) {
                if (t[i - 1][maxRightIndex] - (maxRightIndex - j) < t[i - 1][j]) {
                    maxRightIndex = j;
                }
                maxFromRight[j] = t[i - 1][maxRightIndex] - (maxRightIndex - j);
            }
            for (int j = 1; j < m; j++) {
                if (t[i - 1][maxLeftIndex] - (j - maxLeftIndex) < t[i - 1][j]) {
                    maxLeftIndex = j;
                }
                maxFromLeft[j] = t[i - 1][maxLeftIndex] - (j - maxLeftIndex);
            }

            for (int j = 0; j < m; j++) {
                t[i][j] += max(maxFromLeft[j], maxFromRight[j]);
            }
        }
        for (int i = 0; i < m; i++) res = max(res, t[n - 1][i]);
        return res;
    }
};