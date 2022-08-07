#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> t(5, 1);
        vector<int> temp(5, 0);
        const int mod = 1000000007;
        for (int i = 1; i < n; i++) {
            temp[0] = t[1];
            temp[1] = (t[0] + t[2]) % mod;
            temp[2] = ((t[0] + t[1])%mod + (t[3] + t[4]) % mod)%mod;
            temp[3] = (t[2] + t[4]) % mod;
            temp[4] = t[0];
            t = temp;
            temp.resize(5, 0);
        }
        int res = 0;
        for (int i = 0; i < 5; i++) {
            res = (res + t[i]) % mod;
        }
        return res;
    }
};