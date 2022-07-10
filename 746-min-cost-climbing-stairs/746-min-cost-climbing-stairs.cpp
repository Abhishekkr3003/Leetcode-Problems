
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Time: O(n)
    Space: O(1)
    Tag: DP - Fibonacci pattern
    Difficulty: E
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int f = 0, s = cost[0], t = 0;
        for (int i = 1; i < cost.size();i++){
            t = min(f, s) + cost[i];
            f = s;
            s = t;
        }
        return t;
    }
};