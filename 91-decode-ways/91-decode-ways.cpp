
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Time: O(n)
    Space: O(n) // can be solved in O(1) space as we required only previous two terms to calculate the next term.
    Tag: DP - Fibonacci Pattern
    Difficulty: M
*/

class Solution {
public:
    int numDecodings(string s) {
        unordered_set<string> mp = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
        vector<int> t(s.length() + 1);
        t[0] = 1;
        t[1] = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < s.length(); i++) {
            t[i + 1] = 0;
            if (mp.find(s.substr(i, 1)) != mp.end()) t[i + 1] += t[i];
            if (mp.find(s.substr(i-1, 2)) != mp.end()) t[i + 1] += t[i - 1];
        }
        return t[s.length()];
    }
};