/* 
    Time: O(n^2)
    Space: O(n)
    Tag: DP - LIS (n^2)
    Difficulty: M
*/

class Solution {
public:
    int longestStrChain(vector<string> &words) {
        unordered_map<int, vector<pair<string, int>>> mp;
        for (string &s : words) {
            mp[s.length()].push_back({s, 1});
        }
        int res = 1;
        for (int i = 2; i <= 16; i++) {
            if (mp.find(i) == mp.end() || mp.find(i - 1) == mp.end()) continue;
            for (int j = 0; j < mp[i].size(); j++) {
                for (int k = 0; k < mp[i - 1].size(); k++) {
                    int ptr1 = 0, ptr2 = 0;
                    while (ptr2 < i - 1 && mp[i][j].first[ptr1] == mp[i - 1][k].first[ptr2]) {
                        ptr1++;
                        ptr2++;
                    }
                    ptr1++;
                    while (ptr2 < i - 1 && mp[i][j].first[ptr1] == mp[i - 1][k].first[ptr2]) {
                        ptr1++;
                        ptr2++;
                    }
                    if (ptr2 == i - 1) {
                        mp[i][j].second = max(mp[i][j].second,mp[i - 1][k].second + 1);
                        res = max(res, mp[i][j].second);
                    }
                }
            }
        }
        return res;
    }
};