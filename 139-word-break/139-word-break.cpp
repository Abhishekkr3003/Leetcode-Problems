
/* 
    Time: O(n^3)
    Space: O(n)
    Tag: DP - MCM Modified (Original MCM will take O(n^2) space)
    Difficulty: M
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> t(s.length() + 1, false);
        t[0] = true;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= i; j++) {
                // cout << s.substr(j - 1, i - j + 1) << endl;
                if (st.find(s.substr(j - 1, i - j + 1)) != st.end()) {
                    t[i] = t[i] || t[j - 1];
                }
            }
        }
        return t[s.length()];
    }
};