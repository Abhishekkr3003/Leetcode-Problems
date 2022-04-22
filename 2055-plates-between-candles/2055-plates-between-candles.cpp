/* 
    Time: O(nlogn)
    Space: O(n)
    Tag: Binary Search (Lower Bound and Upper Bound)
    Difficulty: EM
*/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        vector<int> t(s.length(),INT_MAX);
        int idx=0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '|') t[idx++]=i;
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