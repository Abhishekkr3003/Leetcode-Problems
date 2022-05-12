/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int checkRecord(int n) {
        if(n==1) return 3;
        vector<vector<long long>> t(3, vector<long long>(n + 1));
        t[0][0] = 0;
        t[1][0] = 0;
        t[2][0] = 0;
        t[0][1] = 1; // P
        t[1][1] = 1; // L
        t[2][1] = 0; // LL

        int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            t[0][i] = ((long long)t[0][i - 1] + t[1][i - 1] + t[2][i - 1]) % mod;
            t[1][i] = t[0][i - 1];
            t[2][i] = t[1][i - 1];
        }
        long long res = 0;
        res = (t[0][n] + t[1][n] + t[2][n]) % mod;
        res = (res + 2 * (t[0][n - 1] + t[1][n - 1] + t[2][n - 1])) % mod;
        for (int i = 2; i <= n / 2; i++) {
            res = (res + 2 * (((t[0][i - 1] + t[1][i - 1] + t[2][i - 1]) % mod) * ((t[0][n - i] + t[1][n - i] + t[2][n - i]) % mod) % mod)) % mod;
        }
        if (n & 1) {
            res = (res + (((t[0][n / 2] + t[1][n / 2] + t[2][n / 2])%mod) * ((t[0][n / 2] + t[1][n / 2] + t[2][n / 2])%mod)%mod)) % mod;
        }
        return (int)res;
    }
};