/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, ones = 0, zeros = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '0') zeros++;
            else ones++;
            if (s[i] != s[i + 1]) {
                res += min(ones, zeros);
                if (s[i + 1] == '1') ones = 0;
                else zeros = 0;
            }
        }
        int n = s.length();
        if (s[n-1] == '0') zeros++;
        else ones++;
        res += min(ones, zeros);
        return res;
    }
};