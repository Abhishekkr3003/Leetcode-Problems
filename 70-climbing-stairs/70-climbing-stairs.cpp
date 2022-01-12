
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Time: O(n)
    Space: O(1)
    Tag: DP - Fibonacci Pattern
    Difficulty: E
*/

class Solution {
public:
    int climbStairs(int n) {
        int f = 1, s = 1, t = 0;
        if (n < 2) return 1;
        for (int i = 1; i < n; i++) {
            t = f + s;
            f = s;
            s = t;
        }
        return t;
    }
};