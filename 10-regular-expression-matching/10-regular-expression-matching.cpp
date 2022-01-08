class Solution {
    vector<vector<int>> t;

    bool recur(string s, string p, int i, int j) {
        if (i < 0) {
            if (j < 0)
                return true;
            else if (p[j] == '*')
                return recur(s, p, i, j - 2);
            else
                return false;
        }
        if (j < 0) return false;

        if (t[i][j] != -1) return t[i][j];

        if (j - 1 >= 0 && p[j] == '*') {
            if (p[j - 1] == '.')
                return t[i][j] = recur(s, p, i, j - 2) ||

                                 recur(s, p, i - 1, j);
            else if (s[i] == p[j - 1])
                return t[i][j] =
                           (recur(s, p, i, j - 2) || recur(s, p, i - 1, j));
            else
                return t[i][j] = recur(s, p, i, j - 2);
        }
        if (p[j] == '.')
            return t[i][j] = recur(s, p, i - 1, j - 1);
        else if (s[i] == p[j])
            return t[i][j] = recur(s, p, i - 1, j - 1);
        return t[i][j] = false;
    }

   public:
    bool isMatch(string s, string p) {
        t.resize(31, vector<int>(31, -1));
        return recur(s, p, s.length() - 1, p.length() - 1);
    }
};