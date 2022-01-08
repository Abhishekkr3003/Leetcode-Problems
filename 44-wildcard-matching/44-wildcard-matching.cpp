class Solution {
   public:
    bool isMatch(string s, string p) {
        vector<bool> t(s.length() + 1, false), temp;
        t[0] = true;
        for (int i = 1; i <= p.length(); i++) {
            temp.clear();
            temp.resize(s.length() + 1);
            temp[0] = p[i - 1] == '*' ? t[0] : 0;
            for (int j = 1; j <= s.length(); j++) {
                if (p[i - 1] == '*')
                    temp[j] = temp[j - 1] || t[j - 1] || t[j];
                else if (p[i - 1] == '?')
                    temp[j] = t[j - 1];
                else
                    temp[j] = t[j - 1] && (p[i - 1] == s[j - 1]);
            }
            t = temp;
        }
        return t[s.length()];
    }
};