#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    string solve(string A, int i, int j) {
        if (i < 0 || j >= A.length()) return A.substr(i + 1, j - i - 1);
        while (i >= 0 && j < A.length() && A[i] == A[j]) i--, j++;
        return A.substr(i + 1, j - i - 1);
    }

public:
    string longestPalindrome(string A) {
        if (A.length() == 0) return "";
        string res = A.substr(0, 1);
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] == A[i + 1]) {
                string res1 = solve(A, i - 1, i + 2);
                if (res1.length() > res.length()) res = res1;
            }
            string res2 = solve(A, i - 1, i + 1);
            if (res2.length() > res.length()) res = res2;
        }
        return res;
    }
};