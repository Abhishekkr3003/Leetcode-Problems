
/* 
    Time: O(n)
    Space: O(1)
    Tag: Two Pointers
    Difficulty: ME
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    bool isPalindrome(int i, int j, string s) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        bool oneDown = false;
        while (i < j) {
            if (s[i] == s[j]) {
                i++, j--;
            } else {
                // cout << isPalindrome(i + 1, j, s) << endl;
                // cout << isPalindrome(i, j - 1, s) << endl;
                return (isPalindrome(i + 1, j, s) || isPalindrome(i, j - 1, s));
            }
        }
        return true;
    }
};