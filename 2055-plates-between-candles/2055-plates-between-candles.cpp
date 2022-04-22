/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        vector<int> t;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '|') t.push_back(i);
        }
        vector<int> res(queries.size());
        int i = 0;
        for (vector<int> &query : queries) {
            int idx1 = lower_bound(t.begin(), t.end(), query[0]) - t.begin();
            int idx2 = upper_bound(t.begin(), t.end(), query[1]) - t.begin() - 1;
            if (idx1 < idx2) {
                res[i] += t[idx2] - t[idx1] - 1 - (idx2 - idx1 - 1);
            }
            i++;
        }
        return res;
    }
};